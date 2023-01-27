/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:32:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/27 17:21:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_echo.c
int		ft_echo(char **cmd);
//	ft_exec_builtins.c
int		ft_exec_builtins(t_args *args, char **command);
//	ft_export.c
int		ft_export(char **cmd, t_args *args);
//	ft_export_utils.c
char	*ft_get_value(char **cmd);
char	*ft_new_env(char *env);
//	ft_pwd.c
int		ft_pwd(void);
//	ft_cd.c
int		ft_cd(char **cmd);
//	ft_unset.c
int		ft_unset(char **cmd, t_args *args);

//	ft_env_utils.c
char	*ft_get_var_name(char *variable);
char	*ft_getenv(t_args *args, char *variable);
int		ft_get_envp_size(char **envp);
char	**ft_remove_var(t_args *args, char *variable);

#endif
