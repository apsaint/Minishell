/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:57:00 by apsaint-          #+#    #+#             */
/*   Updated: 2018/11/16 08:31:40 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	if ((maillon = malloc(sizeof(*maillon) * content_size)) == NULL)
		return (NULL);
	if (content == NULL)
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	else
	{
		if ((maillon->content = malloc(sizeof(void) * content_size)) == NULL)
			return (NULL);
		ft_memmove(maillon->content, content, content_size);
		maillon->content_size = content_size;
	}
	maillon->next = NULL;
	return (maillon);
}
