/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:12:45 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/05 10:29:01 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_options(char *s)
{
	int size;
	int i;

	size = ft_strlen(s);
	i = 1;
	if (ft_strcmp(s, "-") == 0)
		return (-2);
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

int		cd_error(char **av, int opt)
{
	if (opt == -2)
		ft_putendl("minishell: cd: HOME is not set");
	else if (opt == 0)
	{
		ft_putendl("minishell: cd: OLDPWD is not set");
		return (0);
	}
	else if (opt == -1)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr(av[1]);
		ft_putstr(": invalid option\ncd: usage: cd [-] [dir]\n");
	}
	free_tab(av);
	return (0);
}

int		change_dir_print(char **av)
{
	char	new_path[4097];
	char	old_pwd[4097];

	if (find_env_var("PWD") != -1)
		ft_strcpy(new_path, env_list.data[find_env_var("PWD")].value);
	if (find_env_var("OLDPWD") != -1)
		ft_strcpy(old_pwd, env_list.data[find_env_var("OLDPWD")].value);
	else
		return (cd_error(av, 0));
	set_env_var("OLDPWD", new_path);
	chdir(old_pwd);
	ft_putendl(old_pwd);
	return (set_env_var("PWD", old_pwd));
}

int		change_dir(int opt, char **av)
{
	char	new_path[4097];
	char	old[4097];

	if (opt == -2)
		return (change_dir_print(av));
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
			getcwd(old, sizeof(old));
			set_env_var("OLDPWD", old);
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
		if (find_env_var("HOME") == -1)
			return (cd_error(av, -2));
		chdir(home_path);
		free_tab(av);
		set_env_var("OLDPWD", env_list.data[find_env_var("PWD")].value);
		return (set_env_var("PWD", home_path));
	}
	if (av[1][0] == '-')
		opt = check_options(av[1]);
	if (opt == -1)
		return (cd_error(av, opt));
	else
		change_dir(opt, av);
	free_tab(av);
	return (0);
}
