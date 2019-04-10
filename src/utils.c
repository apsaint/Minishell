/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:37:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/09 10:21:55 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

int		get_table_size(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int		free_env(t_envlist *g_env_list)
{
	free(g_env_list->data);
	ft_memset(g_env_list, 0, sizeof(g_env_list));
	return (0);
}

void	resize_tab(char **tab, int i)
{
	int j;
	int	size;

	j = 0;
	size = get_table_size(tab);
	while (tab[j])
	{
		if (j >= i)
		{
			free(tab[j]);
			if (tab[j + 1])
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
		j += (size > 1) ? 1 : 0;
	}
}

char	*get_value(char *cmd, int *j)
{
	int		p;
	size_t	size;
	char	*name;
	char	*val;

	size = 0;
	p = *j;
	while (cmd[p] && cmd[p] != '$' && cmd[p] != '/')
	{
		p++;
		size++;
	}
	name = ft_strsub(cmd, *j, size);
	*j = p;
	if ((p = (find_env_var(name))) != -1)
		val = ft_strdup(g_env_list.data[p].value);
	free(name);
	if (p == -1)
		return (NULL);
	return (val);
}
