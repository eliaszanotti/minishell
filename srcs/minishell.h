/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2022/12/29 15:57:51 by elias            ###   ########.fr       */
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
	char	**envp;
	char	**command_list;
	char	**instructions;
	char	*prompt;
	int		exit_code;
}	t_args;

// ft_error.c
int	ft_error(int error_code);
// ft_struct_init.c
int	ft_struct_init(t_args *args);
//ft_get_path.c
char	*ft_get_path(char **envp, char *cmd);

#endif





