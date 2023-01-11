/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/01/11 11:50:16 by elias            ###   ########.fr       */
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

typedef struct s_args
{
	char	***stack;
	char	**envp;
	char	**command_list;
	char	**instructions;
	char	*prompt;
	int		exit_code;
	int		i;
	int		j;
}	t_args;

// ft_error.c
int		ft_error(int error_code);
// ft_free.c
char	**ft_freeall(char **tab);
// ft_get_path.c
char	*ft_get_path(char *cmd);
//	ft_parse_quotes.c
char	*ft_replace_env(char *str);
int		ft_remove_quotes(t_args *args);
// ft_parsing.c
int		ft_get_stack_size(t_args *args);
char	**ft_copy_stack(t_args *args, int i, int j);
int		ft_init_stack(t_args *args);
int		ft_get_stack(t_args *args);
int		ft_remove_quotes(t_args *args);
// ft_struct_init.c
int		ft_struct_init(t_args *args);
char	**ft_copy_stack(t_args *args, int i, int j);
// ft_utils.c
int		ft_is_delimiter(char *str); //temp
char	*ft_remove_quotes(char *str);
void	*ft_exit(t_args *args);
void	ft_free_args(t_args *args);

int		ft_split_quote(t_args *args, char *s, char c);

char	*replace_env(char *str);

int		ft_check_cmd(t_args *args);
int		ft_open_dir(char **cmd);
int		ft_echo(char **cmd);
char	*ft_get_dir_name(char *cwd);

#endif
