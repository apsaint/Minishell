/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:20:55 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 11:10:17 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t tmp;
	size_t tsrc;

	i = 0;
	tsrc = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	tmp = i;
	while (*src != '\0' && (i + 1) < size)
	{
		dst[i++] = *src;
		src++;
	}
	if (tmp != size)
		dst[i] = '\0';
	return (tmp + tsrc);
}
