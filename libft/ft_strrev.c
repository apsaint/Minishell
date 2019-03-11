/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:47:17 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 13:08:23 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	size_t	taille;
	size_t	i;

	taille = ft_strlen(str);
	i = 0;
	if ((rev = (char *)malloc(sizeof(*rev) * (taille + 1))) == 0)
		return (NULL);
	while ((int)taille-- >= 0)
	{
		rev[i] = str[taille];
		i++;
	}
	rev[i] = '\0';
	return (rev);
}
