/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:56:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 14:05:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

//	ft_env.c
char	*replace_env(char *str);
//	ft_error.c
int		ft_error(int error_code);
//	ft_exec_builtins.c
//	ft_free.c
char	**ft_freeall(char **tab);
//	ft_get_path.c
char	*ft_get_path(char *cmd);
//	ft_get_prompt.c
char	*ft_get_prompt(char *cwd);
//	ft_struct_init.c
int		ft_struct_init(t_args *args);
int		ft_reset_struct(t_args *args);
//	ft_utils.c
char	ft_is_delimiter(char *str);
char	ft_is_redirect(char *str);
void	ft_sig_ignore(int sig);
void	*ft_exit(t_args *args);
void	ft_free_args(t_args *args);

#endif