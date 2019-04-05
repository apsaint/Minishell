/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:46:43 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/05 15:31:38 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_env_path(char *str, char **n_env)
{
	char	**tmp;
	int		i;

	i = 0;
	if (n_env == NULL)
		return (ENV_ERROR);
	while (n_env[i])
	{
		tmp = ft_strsplit(n_env[i], '=');
		if (ft_strcmp(tmp[0], str) == 0)
		{
			free_tab(tmp);
			return (i);
		}
		free_tab(tmp);
		i++;
	}
	return (ENV_ERROR);
}

int		my_env_error(char **cmd)
{
	ft_putendl("minishell: env: invalid option");
	ft_putendl("env: usage: env [-i]");
	return (free_tab(cmd));
}

int		my_env_no_cmd(char **n_env, char **cmd)
{
	int i;

	i = 0;
	if (n_env)
	{
		while (n_env[i])
			ft_putendl(n_env[i++]);
		free_tab(n_env);
	}
	free_tab(cmd);
	return (0);
}
