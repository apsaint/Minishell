/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:12:45 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/13 14:53:33 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		my_cd(char **av)
{
	int		path_ind;
	char	*path;
	char	*new_path;

	if ((path_ind = find_env_var("PWD")) != -1)
		path = env_list.data[path_ind].value;
	if (!av[1])
	{
		chdir(path);
		free(env_list.data[path_ind].value);
		env_list.data[path_ind].value = ft_strdup(path);
		return (0);
	}
	if (ft_strcmp(av[1], "..") == 0)
		new_path = get_prec_path(path);
	if (av[1][0] == '/')
	new_path = ft_strdup(av[1]);
	else
	{
		if (ft_strcmp(av[1], "..") == 0)
			new_path = get_prec_path(path);
		ft_strcat(path, "/");
		new_path = ft_strjoin(path, av[1]);
	}
	if ((access(new_path, F_OK)) != 0)
		ft_putendl("cd: no such file or directory");
	else
	{
		if (access(new_path, X_OK) == 0)
		{
			chdir(new_path);
			free(env_list.data[path_ind].value);
			env_list.data[path_ind].value = ft_strdup(new_path);
		}
		else
			ft_putendl("cd: permission denied");
	}
	free(new_path);
	return (0);
}
