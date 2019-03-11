/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:30:36 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/08 14:55:24 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t j;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && 0 < len)
	{
		j = 0;
		if (*haystack == *needle)
		{
			while (*haystack == *needle && *needle != '\0' && len > j)
			{
				needle++;
				haystack++;
				j++;
			}
			if (j == ft_strlen(needle - j))
				return ((char *)(haystack - j));
			needle -= j;
			haystack -= j;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
