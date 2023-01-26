/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 17:35:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_builtins(t_args *args, char **command)
{
	int	i;

	i = -1;
	if (!ft_strcmp(command[0], "echo") && ft_echo(command))
		return (1);
	else if (!ft_strcmp(command[0], "cd") && ft_cd(command))
		return (1);
	else if (!ft_strcmp(command[0], "pwd") && ft_pwd())
		return (1);




	else if (!ft_strcmp(command[0], "export"))
	{
		if(ft_export(command, args))//TODO error malloc
			return (ft_error(99));
		return (1);
	}
	else if (!ft_strcmp(command[0], "unset"))
	{
		if(ft_unset(command, args))//TODO error malloc
			return (ft_error(99));
		return (1);	
	}
	else if (!ft_strcmp(command[0], "env"))
	{
		while (args->envp[++i])
			printf("%s\n", args->envp[i]);
		return (1);
	}
	else if (!ft_strcmp(command[0], "exit"))
		ft_exit(args);
	return (0);
}
