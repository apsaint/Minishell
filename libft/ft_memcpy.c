/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:17:10 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 12:24:51 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
