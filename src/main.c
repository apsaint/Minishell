/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:17:19 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/11 14:13:17 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	char	str[4097];
	int i = 0;

	if (access(av[1], F_OK) != -1)
		ft_putstr("minishell>\n");
	ft_putstr(getcwd(str, sizeof(str)));
	ft_putchar('\n');
	if (chdir("/tmp") == 0)
		ft_putstr(getcwd(str, sizeof(str)));
	ft_putchar('\n');
	while(env[i])
		ft_putendl(env[i++]);
}
