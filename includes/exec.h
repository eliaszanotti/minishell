/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:27:03 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/22 10:40:49 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

typedef struct s_args	t_args;

int		ft_add_pid(t_args *args, pid_t pid);
int		ft_child_execution(t_args *args, char **command, int last);
int		ft_exec(t_args *args);
void	ft_exit_and_free(t_args *args, int error_code, char *path, char **command);
int		ft_heredoc(t_args *args, char *delimiter);
int		ft_redirect(t_list *instruction, t_args *args);
int		ft_wait_execution(t_args *args);

#endif
