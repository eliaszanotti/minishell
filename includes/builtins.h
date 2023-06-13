/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:32:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/13 14:43:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_echo.c
int		ft_echo(t_args *args, char **cmd);
//	ft_env.c
int		ft_env(t_args *args);
//	ft_exit.c
int		ft_exit(t_args *args, char **command);
//	ft_exec_builtins.c
int		ft_exec_builtins(t_args *args, char **command);
//	ft_export.c
int		ft_add_var_to_envp(t_args *args, char *name, char *value, int add);
int		ft_export(t_args *args, char **cmd);
//	ft_export_utils.c
char	*ft_get_value(char **cmd);
//	ft_pwd.c
int		ft_pwd(t_args *args);
//	ft_cd.c
int		ft_cd(t_args *args, char **cmd);
//	ft_unset.c
int		ft_unset(t_args *args, char **cmd);
//	ft_env_utils.c
int		ft_is_variable(char c);
char	*ft_get_var_name(char *var, int *add);
char	*ft_get_var_value(t_args *args, char *var);

#endif
