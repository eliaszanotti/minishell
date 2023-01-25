/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/01/25 13:59:35 by tgiraudo         ###   ########.fr       */
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
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# include "exec.h"
# include "builtins.h"
# include "parsing.h"
# include "utils.h"

typedef struct s_args
{
	char	***stack;
	char	**envp;
	char	**command_list;
	char	*prompt;
	int		exit_code;
	int		infile;
	int		outfile;
	int		fdd;
}	t_args;

#endif
