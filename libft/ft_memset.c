/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:19:05 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/13 15:33:10 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*m;
	size_t	i;

	i = 0;
	if (len == 0)
		return (b);
	m = (char *)b;
	while (len > i)
	{
		m[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
