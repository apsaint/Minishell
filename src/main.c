/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:17:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/04/03 16:05:47 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int		main(int ac, char **av, char **env)
{
	char			*input;
	int				i;
	char			**tab;
	int				ret;
	struct	stat	fs;

	init_venv(ac, av, env);
	while (42)
	{
		i = 0;
		if (fstat(STDIN_FILENO, &fs) == 0)
			if (!S_ISFIFO(fs.st_mode) && !S_ISREG(fs.st_mode))
				ft_putstr("minishell> ");
		if ((ret = get_cmd(&input)) == -1)
		{
			free(input);
			ft_putchar('\n');
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
