/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:00:13 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/05 16:00:12 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		my_env_exe(char **cmd, int ind, char **n_env)
{
	int		j;
	int		size;
	char	**n_cmd;

	size = 0;
	if (cmd[ind])
	{
		while (cmd[ind++])
			size++;
		if ((n_cmd = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
			return (ALLOC_ERROR);
		j = 0;
		ind -= (size + 1);
		while (size--)
			n_cmd[j++] = ft_strdup(cmd[ind++]);
		n_cmd[j] = NULL;
	}
	else
	{
		n_cmd = NULL;
		return (my_env_no_cmd(n_env, cmd));
	}
	free_tab(cmd);
	return (search_path(n_cmd, "PATH", n_env));
}

int		my_env_i(char **cmd, int i)
{
	int		j;
	int		size;
	char	**n_env;

	size = 0;
	j = 0;
	if (ft_strchr(cmd[i], '='))
	{
		while (cmd[i])
			size += (ft_strchr(cmd[i++], '=')) ? 1 : 0;
		i -= size;
		if ((n_env = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
			return (ALLOC_ERROR);
		while (cmd[i] && ft_strchr(cmd[i], '='))
			n_env[j++] = ft_strdup(cmd[i++]);
		n_env[j] = NULL;
	}
	else
		n_env = NULL;
	return (my_env_exe(cmd, i, n_env));
}

int		my_env_no_param(char **cmd, int i)
{
	int		s;
	int		j;
	int		k;
	int		size;
	char	**n_env;
	char	**tmp;

	s = 0;
	j = 0;
	k = 0;
	//c = 0;
	/*
	while (cmd[i] && ft_strchr(cmd[i], '='))
	{
		s++;
		i++;
	}*/
	if (ft_strchr(cmd[i], '='))
	{
		tmp = cpy_env();
		while (cmd[i])
			s += (ft_strchr(cmd[i++], '=')) ? 1 : 0;
		i -= s;
		size = env_list.count;
		if ((n_env = (char **)malloc(sizeof(char *) * ((size + s) + 1))) == NULL)
			return (ALLOC_ERROR);
		while (size--)
			n_env[j++] = ft_strdup(tmp[k++]);
		while (s--)
			n_env[j++] = ft_strdup(cmd[i++]);
		n_env[j] = NULL;
		free_tab(tmp);
	}
	else
		n_env = cpy_env();
	return (my_env_exe(cmd, i, n_env));
	//s = 0;
	//j = i;
	/*while (cmd[i])
	{
		i++;
		s++;
	}
	if (cmd[i])
	{
		if ((n_cmd = (char **)malloc(sizeof(char *) * (s + 1))) == NULL)
			return (ALLOC_ERROR);
		c = 0;
		while (s--)
			n_cmd[c++] = ft_strdup(cmd[j++]);
		n_cmd[c] = NULL;
	}
	else
	{
		n_cmd = NULL;
		return (my_env_no_cmd(n_env, cmd));
	}
	free_tab(cmd);
	return (search_path(n_cmd, "PATH", n_env));*/
}

int		my_env(char **cmd)
{
	int i;

	i = 1;
	if (!cmd[i])
	{
		free_tab(cmd);
		return (print_env());
	}
	else
	{
		if (ft_strcmp(cmd[i++], "-i") == 0)
		{
			if (!cmd[i])
				return (free_tab(cmd));
			return (my_env_i(cmd, i));
		}
		else
		{
			if (cmd[i-1][0] == '-')
				return (my_env_error(cmd));
			if (!cmd[i])
				return (free_tab(cmd));
			return (my_env_no_param(cmd, i));
		}
	}
}
