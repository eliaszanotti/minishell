/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 14:44:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <limits.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# include "exec.h"
# include "builtins.h"
# include "parsing.h"
# include "utils.h"

typedef struct s_envp
{
	char			*name;
	char			*value;
	int				equal;
	struct s_envp	*next;
}	t_envp;

typedef struct s_args
{
	t_list	*stack;
	t_envp	*envp;
	char	**char_envp;
	t_list	*command_list;
	char	*prompt;
	pid_t	*pid_tab;
	int		*close_tab;
	int		exit_code;
	int		infile;
	int		outfile;
	int		fdd;
	int		size;
	int		equal;
	int		last;
	int		heredoc_stop;
}	t_args;

extern int	g_last_errno;

#endif
