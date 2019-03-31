/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:00:13 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/31 12:01:07 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
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
		if (ft_strcmp(cmd[i], "-i") == 0)
		{
				j = ++i;
				while (cmd[i] && ft_strchr(cmd[i], '='))
				{
						s++;
						i++;
				}
				if (s > 0)
				{
					if ((n_env = (char **)malloc(sizeof(char *) * (s + 1))) == NULL)
						return (ALLOC_ERROR);
					while (s--)
						n_env[c++] = ft_strdup(cmd[j++]);
					n_env[c] = NULL;
				}
				else
					n_env = NULL;
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
					n_cmd = NULL;
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
				free_tab(cmd);
				return (search_path(n_cmd, "PATH", n_env));
		}
		else
		{
			j = i;
			while (cmd[i] && ft_strchr(cmd[i], '='))
			{
				s++;
				i++;
			}
			printf("%d %d\n", i, j);
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
		return (free_tab(cmd));
	}
}
