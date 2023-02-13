/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/02/13 13:54:33 by ezanotti         ###   ########.fr       */
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

typedef struct s_envp
{
	char			*name;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_args
{
	t_list	*stack;
	t_envp	*envp;
	char	**char_envp;
	char	**command_list;
	t_list	*cl;
	char	*prompt;
	pid_t	*pid_tab;
	int		exit_code;
	int		infile;
	int		outfile;
	int		fdd;
	int		size;
}	t_args;

t_envp	*ft_envpnew(char *name, char *value);
t_envp	*ft_envplast(t_envp *envp);
void	ft_envpadd_back(t_envp **lst, t_envp *new);
int		ft_envpsize(t_envp *envp);

#endif
