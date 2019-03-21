/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:54:36 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/21 08:55:35 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_input(int c, char **line, char *cmd)
{
	char	*tmp;

	if (c > 0)
	{
		if (c++ == 1)
			*line = ft_strdup(cmd);
		else
		{
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(tmp, cmd);
			free(tmp);
		}
	}
	else
		*line = ft_strdup(cmd);
	return (c);
}

int		get_cmd(char **line)
{
	char	*cmd;
	int		b;
	char	*tmp;
	int		c;

	c = 0;
	if ((cmd = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (ALLOC_ERROR);
	ft_memset(cmd, '\0', BUFF_SIZE);
	while ((b = read(0, cmd, BUFF_SIZE)) > 0)
	{
		cmd[b] = '\0';
		if ((tmp = ft_strchr(cmd, '\n')) == NULL)
			c++;
		c = get_input(c, line, cmd);
		if ((tmp = ft_strchr(*line, '\n')) != NULL)
		{
			*tmp = '\0';
			break ;
		}
	}
	free(cmd);
	if (!b)
		return (-1);
	return (1);
}
