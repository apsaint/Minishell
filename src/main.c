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

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int main(int ac, char **av, char **env)
{
	char	*input;
	char	**tab;
	char	**cpy;

	(void)ac;
	(void)av;
	init_venv(env);
	while(42)
	{
		ft_putstr("minishell> ");
		if (get_next_line(0, &input) == -1)
		{
			free(input);
			continue ;
		}
		tab = ft_strsplit(input, ' ');
		if (ft_strcmp(tab[0], "cpy") == 0)
		{
			int i = 0;
			cpy = cpy_env();
			while (cpy[i])
				ft_putendl(cpy[i++]);
		}
		if (switch_command(tab) == -1)
		{
			free_tab(tab);
			break ;
		}
	}
	free(env_list.data);
}
