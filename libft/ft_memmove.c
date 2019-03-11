/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:23:19 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 11:01:30 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dst;
	s = (char *)src;
	i = -1;
	if (dst < src)
	{
		while (++i < (int)len)
			d[i] = s[i];
	}
	else
	{
		d += (len - 1);
		s += (len - 1);
		while (len--)
		{
			*d = *s;
			s--;
			d--;
		}
	}
	return (dst);
}
