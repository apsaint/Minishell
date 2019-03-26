/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:37:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/26 17:41:32 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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

void	free_env(t_envlist *env_list)
{
	free(env_list->data);
	ft_memset(env_list, 0, sizeof(env_list));
}

int		ft_get_env(char **cmd, int j, int ind)
{
	char	*name;
	char	*value;
	char	*val;
	char	*tmp;
	char	*end;
	size_t	size;
	int		i;
	int		a;
	int		e;
	int		d;

	size = 0;
	a = 0;
	d = 0;
	e = 0;
	if (j != 1)
	{
		tmp = ft_strsub(cmd[ind], 0, j - 1);
		d = 1;
	}
	while (cmd[ind][j] && cmd[ind][j] != '$' && cmd[ind][j] != '/')
	{
		j++;
		size++;
	}
	name = ft_strsub(cmd[ind], (j - size), size);
	if ((i = find_env_var(name)) != -1)
	{
		val = ft_strdup(env_list.data[i].value);
		a = 1;
	}
	free(name);
	if (cmd[ind][j] == '/')
	{
		size = 1;
		while (cmd[ind][j])
		{
			j++;
			size++;
		}
		end = ft_strsub(cmd[ind], (j - size), size);
		e = 1;
	}
	if (a == 1)
	{
		if (e == 1)
		{
			free(cmd[ind]);
			value = ft_strjoin(val, end);
			free(val);
			free(end);
			if (d == 1)
			{
				cmd[ind] = ft_strjoin(tmp, value);
				free(tmp);
			}
			else
				cmd[ind] = ft_strdup(value);
			free(value);
		}
		else
		{
			free(cmd[ind]);
			if (d == 1)
			{
				cmd[ind] = ft_strjoin(tmp, val);
				free(tmp);
			}
			else
				cmd[ind] = ft_strdup(val);
			free(val);
		}
		return (j);
	}
	else
	{
		if (e == 1)
		{
			free(cmd[ind]);
			if (d == 1)
			{
				cmd[ind] = ft_strjoin(tmp, end);
				free(tmp);
			}
			else
				cmd[ind] = ft_strdup(end);
			free(end);
			return (j);
		}
		else
		{
			if (d == 1)
			{
				free(cmd[ind]);
				cmd[ind] = ft_strdup(tmp);
				free(tmp);
			}
			else
				return (-1);
		}
	}
	return (j);
}

int		ft_get_home(char **cmd, int j, int ind)
{
	char	*home;
	char	*tmp;
	int		size;

	size = 1;
	if (j == 1)
	{
		if (cmd[ind][j] == '/')
		{
			home = ft_strdup(env_list.data[find_env_var("HOME")].value);
			while (cmd[ind][j++])
				size++;
			tmp = ft_strsub(cmd[ind], (j - size), size);
			free(cmd[ind]);
			cmd[ind] = ft_strjoin(home, tmp);
			free(home);
			free(tmp);
			return (j - size);
		}
		else if (!cmd[ind][j])
		{
			free(cmd[ind]);
			cmd[ind] = ft_strdup(env_list.data[find_env_var("HOME")].value);
			return (j);
		}
	}
	else if (j != 1)
		return (j);
	return (-1);
}

void	resize_tab(char **tab, int i)
{
	int j;

	j = 0;
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
		if (size > 1)
			j++;
	}
}

char	**ft_strsplit_input(char *str, char c)
{
	char	**cmd;
	int		i;
	int		j;

	i = 0;
	cmd = ft_strsplit(str, c);
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == '$' && cmd[i][j + 1])
				j = ft_get_env(cmd, ++j, i);
			else if (cmd[i][j] == '~')
				j = ft_get_home(cmd, ++j, i);
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
