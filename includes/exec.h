/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:03 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 12:58:30 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_exec.c
int		ft_start_execution(t_args *args);
//	ft_heredoc.c
void	ft_heredoc(char *delimiter, t_args *args);
//	ft_pid_utils.c
int		ft_wait_execution(t_args *args);
int		ft_add_pid(t_args *args, pid_t pid);
//	ft_redirect.c
int		ft_redirect(char **str, t_args *args);

#endif
