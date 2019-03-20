/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:54:36 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/20 18:08:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int		get_cmd(char **line)
{
	char	*cmd;
	int		b;
	char	*ret;
	char	*tmp;

	int c = 0;
	if ((cmd =(char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (ALLOC_ERROR);
	ft_memset(cmd, '\0', BUFF_SIZE);
	while ((b = read(0, cmd, BUFF_SIZE)) > 0)
	{
		cmd[b] = '\0';
		c += b;
		if ((ret = ft_strchr(cmd, '\n')) != NULL && c < BUFF_SIZE)
			*line = ft_strdup(cmd);
		//if ((ret = ft_strchr(cmd, '\n')) == NULL && c > BUFF_SIZE)
		else
		{
				tmp = ft_strdup(*line);
				ft_strclr(*line);
				*line = ft_strjoin(tmp, cmd);
				free(tmp);
		}
		if ((ret = ft_strchr(*line, '\n')) != NULL)
		{
			*ret = '\0';
			break ;
		}
	}
	free(cmd);
	return (1);
}
