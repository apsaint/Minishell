/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:24:35 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/13 17:26:29 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				found;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	found = 0;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			n = 0;
			found = 1;
		}
		*d = *s;
		d++;
		s++;
		dst++;
	}
	if (found == 0)
		return (NULL);
	return (dst);
}
