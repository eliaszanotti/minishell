/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:03 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/01 10:50:12 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_exec.c
int		ft_start_execution(t_args *args);
//	ft_heredoc.c
int		ft_heredoc(t_args *args, char *delimiter);
//	ft_pid_utils.c
int		ft_wait_execution(t_args *args);
int		ft_add_pid(t_args *args, pid_t pid);
//	ft_redirect.c
int		ft_redirect(char **str, t_args *args);

#endif
