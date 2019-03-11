/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:12:18 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/14 16:13:30 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	if ((cpy = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (len > i && s[start] != '\0')
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}
