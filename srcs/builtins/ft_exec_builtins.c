/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/04/27 13:30:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_builtins(t_args *args, char **command)
{
	if (!ft_strcmp(command[0], "echo") && ft_echo(command))
		return (1);
	else if (!ft_strcmp(command[0], "cd") && ft_cd(args, command))
		return (1);
	else if (!ft_strcmp(command[0], "pwd") && ft_pwd())
		return (1);
	else if (!ft_strcmp(command[0], "env") && ft_env(args))
		return (1);
	else if (!ft_strcmp(command[0], "export") && ft_export(command, args))
		return (1);
	else if (!ft_strcmp(command[0], "unset") && ft_unset(args, command))
		return (1);
	else if (!ft_strcmp(command[0], "exit"))
		ft_exit(args);
	return (0);
}
