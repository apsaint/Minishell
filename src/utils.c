/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:37:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/21 11:59:41 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		get_table_size(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	free_env(t_envlist *env_list)
{
	free(env_list->data);
	ft_memset(env_list, 0, sizeof(env_list));
}

int		ft_get_env(char **cmd, int j, int ind)
{
	char	*name;
	char	*value;
	size_t	size;
	int		i;

	size = 0;
	while (cmd[ind][j] && cmd[ind][j] != ' ' && cmd[ind][j] != '$' && cmd[ind][j] != '/')
	{
		j++;
		size++;
	}
	name = ft_strsub(cmd[ind], (j - size), size);
	if ((i = find_env_var(name)) != -1)
	{
		free(name);
		name = ft_strdup(env_list.data[i].value);
		if (cmd[ind][j] == '/')
		{
			size = 1;
			while (cmd[ind][j++])
				size++;
			value = ft_strjoin(name, ft_strsub(cmd[ind], (j - size), size));
			free(name);
			free(cmd[ind]);
			cmd[ind] = ft_strdup(value);
			free(value);
			return (j);
		}
		free(cmd[ind]);
		cmd[ind] = ft_strdup(name);
		free(name);
	}
	else
	{
		free(name);
		return (-1);
	}
	return (j);
}

void	resize_tab(char **tab, int i)
{
	int j;

	j = 1;
	int size = get_table_size(tab);
	while (tab[j])
	{
		if (j >= i)
		{
			free(tab[j]);
			if ( tab[j + 1])
			{
				tab[j] = ft_strdup(tab[j + 1]);
				if ((j + 1) == (size - 1))
				{
					free(tab[j + 1]);
					tab[j + 1] = NULL;
					break ;
				}
			}
			else
				tab[j] = NULL;
		}
		j++;
	}
}

char	**ft_strsplit_input(char *str, char c)
{
	char	**cmd;
	int		i;
	int		j;

	i = 1;
	cmd = ft_strsplit(str, c);
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == '$' && cmd[i][j + 1])
				j = ft_get_env(cmd, ++j, i);
			if (j == -1)
			{
				resize_tab(cmd, i);
				break ;
			}
			j++;
		}
		i++;
	}
	return (cmd);
}
