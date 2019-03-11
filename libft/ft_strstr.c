/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:16:49 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/08 14:48:14 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t j;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		j = 0;
		if (*haystack == *needle)
		{
			while (*haystack == *needle && *needle != '\0')
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
	}
	return (NULL);
}
