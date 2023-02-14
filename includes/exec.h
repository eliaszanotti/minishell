/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:03 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/13 18:47:26 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_child_execution.c
int		ft_execute_child(t_args *args, char **command, int last);
//	ft_exec.c
int		ft_start_execution(t_args *args);
//	ft_heredoc.c
int		ft_heredoc(t_args *args, char *delimiter);
//	ft_pid_utils.c
int		ft_wait_execution(t_args *args);
int		ft_add_pid(t_args *args, pid_t pid);
//	ft_redirect.c
int		ft_redirect(t_list *instruction, t_args *args);

#endif
