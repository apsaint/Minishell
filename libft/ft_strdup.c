/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:15:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/27 11:05:00 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	s;

	s = ft_strlen(s1);

	if ((cpy = (char *)malloc(sizeof(char) * (s + 1))) == 0)
		return (NULL);
	return (ft_strcpy(cpy, s1));
}
