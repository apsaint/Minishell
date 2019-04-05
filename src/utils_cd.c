/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:56:39 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/05 10:29:18 by apsaint-         ###   ########.fr       */
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
	if (size > 0)
		ft_strncpy(new_path, path, size);
	else
		ft_strcpy(new_path, "/");
	if (ft_strcmp(av, "..") != 0)
	{
		ptr = ft_strchr(av, '/');
		ft_strcat(new_path, ptr);
	}
	return (new_path);
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
