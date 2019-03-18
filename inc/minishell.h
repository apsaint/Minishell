/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:11:48 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/14 11:57:48 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ALLOC_ERROR (-1)
# define EXIT_STATUS (1)
# define ARG_ERROR (-1)
# define ENV_ERROR (-1)

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct	s_env
{
	char	name[4097];
	char	value[4097];
}				t_env;

typedef struct	s_envlist
{
	t_env		*data;
	int			size;
	int			count;
}				t_envlist;

t_envlist		env_list;

/* Functions gestions signaux */
void		gestion_sig(int sig);

/* Functions builtin */
int			switch_command(char **cmd);
int			my_echo(char **av);
int			my_cd(char **av);
int			my_set_env(char **cmd);
int			my_unset_env(char **cmd);

/* Functions utils*/
int			get_table_size(char **av);

/* Functions environement*/
int			init_venv(char **env);
int			resize_array(t_envlist *env_list);
int			find_env_var(char *str);
int			add_var_env(t_env *env, char *var, char *name);
int			set_env_var(char *name, char *value);
int			remove_env_var(char *name);
int			print_env(void);
char		**cpy_env(void);

#endif
