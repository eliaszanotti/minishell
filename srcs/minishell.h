/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2022/12/27 17:52:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>

//# include <readline/readline.h>
//# include <readline/history.h>

typedef struct s_args
{
	char *command;
}	t_args;

// ft_error.c
int	ft_error(int error_code);
// ft_struct_init.c
int	ft_struct_init(t_args *args);

#endif
