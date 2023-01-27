/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:56:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/27 20:14:31 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

//	ft_error.c
int		ft_error(int error_code);
//	ft_free.c
void	ft_free_str(char **str);
void	ft_free_stack(char ***stack);
void	ft_free_args(t_args *args);
//	ft_get_path.c
char	*ft_get_path(char *cmd);
//	ft_get_prompt.c
char	*ft_get_prompt(char *cwd);
//	ft_is_type.c
char	*ft_is_builtins(char *cmd);
char	ft_is_delimiter(char *str);
char	ft_is_redirect(char *str);
int		ft_is_command(char *cmd);
//	ft_struct_init.c
int		ft_struct_init(t_args *args);
int		ft_reset_struct(t_args *args);
//	ft_utils.c
void	ft_sig_ignore(int sig);
void	ft_free_args(t_args *args);

#endif
