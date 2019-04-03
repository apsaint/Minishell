/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:12:45 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/03 10:00:36 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prec_path(char *new_path, char *av)
{
	char	*ptr;
	int		size;
	char	path[4097];

	getcwd(path, sizeof(path));
	ptr = ft_strrchr(path, '/');
	size = ft_strlen(path) - ft_strlen(ptr);
	ft_strncpy(new_path, path, size);
	if (ft_strcmp(av, "..") != 0)
	{
		ptr = ft_strchr(av, '/');
		ft_strcat(new_path, ptr);
	}
	return (new_path);
}

int		check_options(char *s)
{
	int size;
	int i;

	size = ft_strlen(s);
	i = 1;
	while (s[i])
	{
		if (s[i] != 'L' && s[i] != 'P')
			return (-1);
		i++;
	}
	if (s[size - 1] == 'L')
		return (2);
	else if (s[size - 1] == 'P')
		return (1);
	return (-1);
}

char	*get_new_path(int opt, char **av)
{
	int			i;
	static char	new_path[4097];

	i = (opt == 0) ? 1 : 2;
	ft_strclr(new_path);
	if (av[i][0] == '/')
		ft_strcpy(new_path, av[i]);
	else
	{
		if (ft_strstr(av[i], ".."))
			get_prec_path(new_path, av[i]);
		else
		{
			getcwd(new_path, sizeof(new_path));
			ft_strcat(new_path, "/");
			ft_strcat(new_path, av[i]);
		}
	}
	return (new_path);
}

int		change_dir(int opt, char **av)
{
	char	new_path[4097];

	ft_strcpy(new_path, get_new_path(opt, av));
	if ((access(new_path, F_OK)) != 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(new_path);
	}
	else
	{
		if (access(new_path, X_OK) == 0)
		{
			chdir(new_path);
			set_env_var("PWD", new_path);
		}
		else
			ft_putendl("cd: permission denied");
	}
	return (0);
}

int		my_cd(char **av)
{
	char	home_path[4097];
	int		opt;

	opt = 0;
	if (find_env_var("HOME") != -1)
		ft_strcpy(home_path, env_list.data[find_env_var("HOME")].value);
	if (!av[1])
	{
		chdir(home_path);
		free_tab(av);
		return (set_env_var("PWD", home_path));
	}
	if (av[1][0] == '-')
		opt = check_options(av[1]);
	if (opt == -1)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr(av[1]);
		ft_putstr(": invalid option\ncd: usage: cd [-L|-P] [dir]\n");
	}
	else
		change_dir(opt, av);
	free_tab(av);
	return (0);
}
