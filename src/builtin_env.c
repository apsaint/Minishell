/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:00:13 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/04 13:50:08 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

int		my_env_exe(char **cmd,int ind, char **n_env)
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
		if (n_env)
		{
			while (n_env[size])
				ft_putendl(n_env[size++]);
			free_tab(n_env);
		}
		free_tab(cmd);
		return (0);
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

/*
int		switch_command_env(char **cmd, char **env)
{
	if (cmd[0] && ft_strcmp(cmd[0], "exit") == 0)
	{
		free_tab(cmd);
		return (-1);
	}
	else if (cmd[0] && ft_strcmp(cmd[0], "cd") == 0)
		return (my_cd_env(cmd, env));
	else if (cmd[0] && ft_strcmp(cmd[0], "env") == 0)
		return (my_env_env(cmd,env));
	else if (cmd[0] && ft_strcmp(cmd[0], "echo") == 0)
		return (my_echo(cmd));
	else
		return (search_path(cmd, "PATH", env));
}
*/

int		my_env(char **cmd)
{
	int		i;
	int		s;
	int		j;
	int		c;
	char	**n_env;
	char	**n_cmd;

	i = 1;
	s = 0;
	j = 0;
	c = 0;
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
			{
				free_tab(cmd);
				return (0);
			}
			return (my_env_i(cmd, i));
		}
		else
		{
			j = i;
			while (cmd[i] && ft_strchr(cmd[i], '='))
			{
				s++;
				i++;
			}
			if (s > 0)
			{
				char **tmp;
				int		size;
				c = 0;
				int k = 0;

				tmp = cpy_env();
				size = env_list.count;
				if ((n_env = (char **)malloc(sizeof(char *) * ((size + s) + 1))) == NULL)
					return (ALLOC_ERROR);
				while (size--)
					n_env[c++] = ft_strdup(tmp[k++]);
				while (s--)
					n_env[c++] = ft_strdup(cmd[j++]);
				n_env[c] = NULL;
				free_tab(tmp);
			}
			else
				n_env = cpy_env();
			s = 0;
			j = i;
			while (cmd[i])
			{
				i++;
				s++;
			}
			if (s > 0)
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
				i = 0;
				n_cmd = NULL;
				if (n_env)
				{
					while (n_env[i])
						ft_putendl(n_env[i++]);
					free_tab(n_env);
				}
				free_tab(cmd);
				return (0);
			}
			free_tab(cmd);
			return (search_path(n_cmd, "PATH", n_env));
		}
	}
}
