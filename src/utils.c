/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:37:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/20 10:37:51 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		get_table_size(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	free_env(t_envlist *env_list)
{
	free(env_list->data);
	ft_memset(env_list, 0, sizeof(env_list));
}
