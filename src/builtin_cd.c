/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:12:45 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/20 10:46:19 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prec_path(char *new_path)
{
	char	*ptr;
	int		size;
	char	path[4097];

	getcwd(path, sizeof(path));
	ptr = ft_strrchr(path, '/');
	size = ft_strlen(path) - ft_strlen(ptr);
	ft_strncpy(new_path, path, size);
	return (new_path);
}

int		my_cd(char **av)
{
	int		path_ind;
	char	home_path[4097];
	char	pwd_path[4097];
	char	new_path[4097];

	if (find_env_var("HOME") != -1)
		ft_strcpy(home_path, env_list.data[find_env_var("HOME")].value);
	if ((path_ind = find_env_var("PWD")) != -1)
		ft_strcpy(pwd_path, env_list.data[path_ind].value);
	if (!av[1] || ft_strcmp(av[1], "~") == 0)
	{
		chdir(home_path);
		free_tab(av);
		return (set_env_var("PWD", home_path));
	}
	if (av[1][0] == '/')
		ft_strcpy(new_path, av[1]);
	else
	{
		if (ft_strcmp(av[1], "..") == 0)
			get_prec_path(new_path);
		else
		{
			getcwd(new_path, sizeof(new_path));
			ft_strcat(new_path, "/");
			ft_strcat(new_path, av[1]);
		}
	}
	if ((access(new_path, F_OK)) != 0)
		ft_putendl("cd: no such file or directory");
	else
	{
		if (access(new_path, X_OK) == 0)
		{
			chdir(new_path);
			free_tab(av);
			return (set_env_var("PWD", new_path));
		}
		else
			ft_putendl("cd: permission denied");
	}
	free_tab(av);
	return (0);
}
