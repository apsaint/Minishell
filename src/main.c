/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:17:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/13 11:38:30 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char	*input;

	int i = 0;
	(void)ac;
	(void)av;
	copy_venv(env);
	while(42)
	{
		ft_putstr("minishell> ");
		//signal(SIGINT, gestion_sig);
		if (get_next_line(0, &input) == -1)
		{
			free(input);
			continue ;
		}
		while (i < env_list.size)
		{
			ft_putstr(env_list.data[i].name);
			ft_putchar(' ');
			ft_putendl(env_list.data[i++].value);
		}
	}
}
