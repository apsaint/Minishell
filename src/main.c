/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:17:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 13:14:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	char	*input;
	int		i;
	char	**tab;

	init_venv(ac, av, env);
	while(42)
	{
		i = 0;
		ft_putstr("minishell> ");
		if (get_next_line(0, &input) == -1 || (ft_strcmp(input, "\0") == 0))
		{
			free(input);
			continue ;
		}
		tab = ft_strsplit(input, ';');
		while (tab[i])
		{
			if (switch_command(tab[i]) == -1)
			{
				free_tab(tab);
				exit(1);
			}
			i++;
		}
		free_tab(tab);
		free(input);
	}
	free_env(&env_list);
}
