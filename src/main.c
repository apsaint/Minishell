/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:17:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 09:15:22 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char	*input;
	char	**tab;

	(void)ac;
	(void)av;
	copy_venv(env);
	while(42)
	{
		int i = 0;
		ft_putstr("minishell> ");
		//signal(SIGINT, gestion_sig);
		if (get_next_line(0, &input) == -1)
		{
			free(input);
			continue ;
		}
		tab = ft_strsplit(input, ' ');
		if (ft_strcmp(tab[0], "cd") == 0)
			my_cd(tab);
		while (i < env_list.size)
		{
			if (ft_strcmp(env_list.data[i].name, "PWD") == 0)
			{
				ft_putendl(env_list.data[i].value);
				break ;
			}
			i++;
		}
	}
}
