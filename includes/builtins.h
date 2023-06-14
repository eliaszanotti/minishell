/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:32:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/14 11:45:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//  BUILTINS
int		ft_add_var_to_envp(t_args *args, char *name, char *value, int add);
int		ft_export(t_args *args, char **cmd);
char	*ft_get_value(char **cmd);
char	*ft_get_var_name(char *var, int *add);
char	*ft_get_var_value(t_args *args, char *var);
int		ft_is_variable(char c);
int		ft_unset(t_args *args, char **cmd);

int		ft_cd(t_args *args, char **cmd);
int		ft_echo(t_args *args, char **cmd);
int		ft_env(t_args *args);
int		ft_exec_builtins(t_args *args, char **command);
int		ft_exit(t_args *args, char **command);
int		ft_pwd(t_args *args);

#endif
