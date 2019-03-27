/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:27:21 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/27 16:12:35 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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
		val = ft_strdup(env_list.data[p].value);
	free(name);
	if (p == -1)
		return (NULL);
	return (val);
}

int		final_parse()

int		ft_get_env(char **cmd, int j, int ind)
{
	//char	*name;
	char	*val;
	char	*tmp;
	char	*end;
	size_t	size;
	//int		i;

	size = 0;
	if (j != 1)
		tmp = ft_strsub(cmd[ind], 0, j - 1);
	else
		tmp = NULL;
	/*
	while (cmd[ind][c] && cmd[ind][c] != '$' && cmd[ind][c] != '/')
	{
		c++;
		size++;
	}
	name = ft_strsub(cmd[ind], j, size);
	j = c;
	if ((i = find_env_var(name)) != -1)
	{
		val = ft_strdup(env_list.data[i].value);
		a = 1;
	}
	free(name);*/
	val = get_value(cmd[ind], &j);
	if (cmd[ind][j] == '/')
	{
		size = ft_strlen(cmd[ind]) - (size_t)j;
		end = ft_strsub(cmd[ind], j, size);
		j += size;
		//e = 1;
	}
	else
		end = NULL;
	return (final_parse(tmp, end, val, cmd[ind]));
	/*
	if (val)
	{
		free(cmd[ind]);
		if (e == 1)
		{
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
			return (ft_strlen(cmd[ind]));
		}
		else
		{
			if (d == 1)
			{
				free(cmd[ind]);
				cmd[ind] = ft_strdup(tmp);
				free(tmp);
				return (ft_strlen(cmd[ind]));
			}
			else
				return (-1);
		}
	}
	return (j);*/
}

int		ft_get_home(char **cmd, int j, int ind)
{
	char	*home;
	char	*tmp;
	int		size;

	if (j == 1)
	{
		if (cmd[ind][j] == '/' || cmd[ind][j] == '$')
		{
			home = ft_strdup(env_list.data[find_env_var("HOME")].value);
			size = ft_strlen(cmd[ind]) - j;
			tmp = ft_strsub(cmd[ind], j, size);
			free(cmd[ind]);
			cmd[ind] = ft_strjoin(home, tmp);
			free(home);
			free(tmp);
		}
		else if (!cmd[ind][j])
		{
			free(cmd[ind]);
			cmd[ind] = ft_strdup(env_list.data[find_env_var("HOME")].value);
		}
		return (j);
	}
	return (j);
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

char	**ft_strsplit_input(char *str, char c)
{
	char	**cmd;
	int		i;
	int		j;

	i = -1;
	cmd = ft_strsplit(str, c);
	while (cmd[++i])
	{
		j = -1;
		while (cmd[i][++j])
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
			if (!cmd[i][j])
				break ;
		}
	}
	return (cmd);
}
