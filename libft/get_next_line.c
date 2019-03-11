/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:20:46 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/11 13:17:29 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		analyse_lec(char **keep, char **line)
{
	char	*tmp;
	char	*ligne;
	int		i;

	i = 0;
	ligne = *keep;
	while (ligne[i] != '\n')
	{
		i++;
		if (ligne[i] == '\0')
			return (0);
	}
	tmp = &ligne[i];
	*tmp = '\0';
	*line = ft_strdup(*keep);
	*keep = ft_strdup(tmp + 1);
	free(ligne);
	return (1);
}

int		lecture(int fd, char *buf, char **keep, char **line)
{
	int		b;
	char	*tmp;

	while ((b = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[b] = '\0';
		if (*keep)
		{
			tmp = *keep;
			*keep = ft_strjoin(tmp, buf);
			ft_strdel(&tmp);
		}
		else
			*keep = ft_strdup(buf);
		if (analyse_lec(keep, line))
			break ;
	}
	if (b > 0)
		return (1);
	return (b);
}

int		check_error(char **line, int fd, char **keep)
{
	if (!line || (fd < 0 || fd >= FD_SIZE) || (read(fd, keep[fd], 0) < 0))
		return (-1);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*keep[FD_SIZE];
	char			*buf;
	int				b;

	if (check_error(line, fd, keep) == -1 ||
			!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (keep[fd])
		if (analyse_lec(&keep[fd], line))
			return (1);
	buf = ft_memset(buf, '\0', BUFF_SIZE);
	b = lecture(fd, buf, &keep[fd], line);
	free(buf);
	if (b != 0 || keep[fd] == NULL || keep[fd][0] == '\0')
	{
		if (!b && *line)
			*line = NULL;
		return (b);
	}
	*line = keep[fd];
	keep[fd] = NULL;
	return (1);
}
