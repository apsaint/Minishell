/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:27:21 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/28 08:51:03 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		final_parse_v(char *tmp, char *end, char *val, char **cmd)
{
	char	*value;

	free(*cmd);
	if (end)
	{
		value = ft_strjoin(val, end);
		free(end);
		if (tmp)
			*cmd = ft_strjoin(tmp, value);
		else
			*cmd = ft_strdup(value);
		free(value);
	}
	else
	{
		if (tmp)
			*cmd = ft_strjoin(tmp, val);
		else
			*cmd = ft_strdup(val);
	}
	free(val);
	if (tmp != NULL)
		free(tmp);
	return (ft_strlen(*cmd));
}

int		final_parse_nv(char *tmp, char *end, char **cmd)
{
	if (end)
	{
		free(*cmd);
		if (tmp)
			*cmd = ft_strjoin(tmp, end);
		else
			*cmd = ft_strdup(end);
		free(end);
	}
	else
	{
		if (tmp)
		{
			free(*cmd);
			*cmd = ft_strdup(tmp);
		}
		else
			return (-1);
	}
	if (tmp != NULL)
		free(tmp);
	return (ft_strlen(*cmd));
}

int		ft_get_env(char **cmd, int j, int ind)
{
	char	*val;
	char	*tmp;
	char	*end;
	size_t	size;

	size = 0;
	if (j != 1)
		tmp = ft_strsub(cmd[ind], 0, j - 1);
	else
		tmp = NULL;
	val = get_value(cmd[ind], &j);
	if (cmd[ind][j] == '/')
	{
		size = ft_strlen(cmd[ind]) - (size_t)j;
		end = ft_strsub(cmd[ind], j, size);
		j += size;
	}
	else
		end = NULL;
	if (val)
		return (final_parse_v(tmp, end, val, &cmd[ind]));
	else
		return (final_parse_nv(tmp, end, &cmd[ind]));
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
