/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:32:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 13:39:33 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_echo.c
int	ft_echo(char **cmd);
//	ft_exec_builtins.c
int	ft_exec_builtins(t_args *args);
//	ft_export.c
int	ft_export(char **cmd, t_args *args);
//	ft_open_dir.c
int	ft_open_dir(char **cmd);
//	ft_unset.c
int	ft_unset(char **cmd, t_args *args);

#endif