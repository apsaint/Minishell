/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:41:59 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/08 12:16:11 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			m = i;
		i++;
	}
	if (s[m] == c)
		return ((char *)s + m);
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
