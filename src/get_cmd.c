/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:54:36 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/03 15:42:22 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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

int		count_command(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
			count++;
	}
	return (count);
}

int		get_unique_cmd(char **line, char *cmd)
{
	char		*tmp;
	struct stat ls;

	tmp = ft_strchr(*line, '\n');
	*tmp = '\0';
	if (fstat(STDIN_FILENO, &ls) == 0)
	{
		if (S_ISFIFO(ls.st_mode) || S_ISREG(ls.st_mode))
		{
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(tmp, ";exit");
			free(tmp);
		}
	}
	free(cmd);
	return (0);
}

int		get_mult_cmd(char **line, char *cmd)
{
	char	*tmp;
	int		c;

	c = 0;
	while (c > -1)
	{
		if (line[0][c] == '\n')
			line[0][c] = ';';
		c++;
		if (line[0][c] == '\0')
			break ;
	}
	tmp = ft_strdup(*line);
	free(*line);
	*line = ft_strjoin(tmp, "exit");
	free(tmp);
	free(cmd);
	return (0);
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
		c += ((tmp = ft_strchr(cmd, '\n')) == NULL) ? 1 : 0;
		c = get_input(c, line, cmd);
		if (count_command(*line) == 1)
			return (get_unique_cmd(line, cmd));
		else if (count_command(*line) > 1)
			return (get_mult_cmd(line, cmd));
	}
	free(cmd);
	if (!b)
		return (-1);
	return (1);
}
