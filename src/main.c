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
		//if (ft_strcmp(tab[0], "cd") == 0)
		//	my_cd(tab);
		if (ft_strcmp(tab[0], "rm") == 0)
			remove_env_var(tab[1]);
		else if (ft_strcmp(tab[0], "add") == 0)
			set_env_var("TEST", "test new var");
		else if (ft_strcmp(tab[0], "exit") == 0)
		{
			free(input);
			while (tab[i])
				free(tab[i++]);
			free(tab);
			break ;
		}
		print_env();
		free(input);
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}

	free(env_list.data);
}
