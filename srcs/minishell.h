/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/01/03 14:37:52 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_args
{
	char	***stack;
	char	**envp;
	char	**command_list;
	char	**instructions;
	char	*prompt;
	int		exit_code;
}	t_args;

// ft_error.c
int		ft_error(int error_code);
// ft_free.c
char	**ft_freeall(char **tab);
// ft_get_path.c
char	*ft_get_path(char **envp, char *cmd);
// ft_parsing.c
int		ft_get_stack_size(t_args *args);
// ft_struct_init.c
int		ft_struct_init(t_args *args);
char	**ft_copy_stack(t_args *args, int i, int j);
int		ft_get_stack(t_args *args);


int	ft_split_quote(t_args *args, char *s, char c);


int	ft_is_delimiter(char *str); //temp

#endif
