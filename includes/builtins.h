/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:32:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 18:13:37 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_echo.c
int		ft_echo(char **cmd);
//	ft_exec_builtins.c
int	ft_exec_builtins(t_args *args, char **command);
//	ft_export.c
int		ft_export(char **cmd, t_args *args, int i);
//	ft_export_utils.c
char	*ft_get_value(char **cmd);
char	*ft_new_env(char *env);
//	ft_open_dir.c
int		ft_open_dir(char **cmd);
//	ft_unset.c
int		ft_unset(char **cmd, t_args *args);
char	*ft_get_var_name(char	*var);

#endif
