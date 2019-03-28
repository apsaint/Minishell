/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:17:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/28 15:55:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*input;
	int		i;
	char	**tab;
	int		ret;

	init_venv(ac, av, env);
	while (42)
	{
		i = 0;
		ft_putstr("minishell> ");
		if ((ret = get_cmd(&input)) == -1)
		{
			free(input);
			continue ;
		}
		tab = ft_strsplit(input, ';');
		while (tab[i])
			if ((ret = switch_command(tab[i++])) == -1)
				break ;
		free_tab(tab);
		free(input);
		if (ret == -1)
			break ;
	}
	free_env(&env_list);
}
