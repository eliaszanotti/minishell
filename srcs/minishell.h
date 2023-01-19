/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/01/19 17:23:52 by elias            ###   ########.fr       */
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

typedef struct s_args
{
	char	***stack;
	char	***instructions;
	char	**envp;
	char	**command_list;
	char	*prompt;
	int		exit_code;
	int		infile;
	int		outfile;
}	t_args;

/*	EXEX	*/
//	ft_exec.c
int		ft_execute_child(t_args *args, char **command, int last, int fdd);
int		ft_execute_command(t_args *args, int size);
int		ft_start_execution(t_args *args);
//	ft_redirect.c
int		ft_redirect(char **str, t_args *args);

/*	PARSING	*/
//	ft_add_to_stack.c
int		ft_add_redirects(t_args *args, char **cmd, int i_stack, int max);
char	**ft_init_instruction(char **cmd, int max);
int		ft_add_command(t_args *args, char **cmd, int i_stack, int max);
//	ft_get_instructions.c
int		ft_get_instructions(t_args *args);
//	ft_get_stack.c
int		ft_get_stack_size(char **command_list, int i, int j);
int		ft_init_stack(t_args *args);
char	**ft_copy_stack(char **command_list, int j);
int		ft_get_stack(t_args *args);
//	ft_parse_quotes.c
char	*ft_replace_env(char *str);
int		ft_parse_quotes(t_args *args);
//	ft_parsing.c
int		ft_parse_args(t_args *args, char *command);
//	ft_split_quote.c
int		ft_split_quote(t_args *args, char *s, char c);

/*	SRCS	*/
//	ft_env.c
char	*replace_env(char *str);
//	ft_error.c
int		ft_error(int error_code);
//	ft_exec_builtins.c
int		ft_exec_builtins(t_args *args);
int		ft_open_dir(char **cmd);
int		ft_echo(char **cmd);
//	ft_free.c
char	**ft_freeall(char **tab);
//	ft_get_path.c
char	*ft_pathjoin(char *s1, char *s2);
char	*ft_get_path(char *cmd);
//	ft_get_prompt.c
char	*ft_get_prompt(char *cwd);
//	ft_struct_init.c
int		ft_struct_init(t_args *args);
//	ft_utils.c
char	ft_is_delimiter(char *str);
void	ft_sig_ignore(int sig);
void	*ft_exit(t_args *args);
void	ft_free_args(t_args *args);

#endif
