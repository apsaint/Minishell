/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:49:45 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/15 11:35:46 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*st1;
	char	*st2;
	size_t	i;
	int		cmp;

	st1 = (char *)s1;
	st2 = (char *)s2;
	i = 0;
	cmp = 0;
	if (n == 0)
		return (0);
	while (n > i)
	{
		if (st1[i] != st2[i])
			return ((unsigned char)st1[i] - (unsigned char)st2[i]);
		i++;
	}
	return (cmp);
}
