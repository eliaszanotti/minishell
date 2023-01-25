/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 16:09:29 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO error
int	ft_exec_builtins(t_args *args)
{
	int	i;

	i = -1;
	if (!ft_strcmp(args->stack[0][0], "echo"))
		return (ft_echo(args->stack[0]));
	else if (!ft_strcmp(args->stack[0][0], "cd"))
		return (ft_open_dir(args->stack[0]));
	else if (!ft_strcmp(args->stack[0][0], "pwd"))
		return (printf("%s\n", getenv("PWD")));
	else if (!ft_strcmp(args->stack[0][0], "export"))
	{
		if(ft_export(args->stack[0], args))//TODO error malloc
			return (ft_error(99));
		printf("\n\n\nOK\n\n\n");
		return (1);	
	}
	else if (!ft_strcmp(args->stack[0][0], "unset"))
	{
		if(ft_unset(args->stack[0], args))//TODO error malloc
			return (ft_error(99));
		return (1);	
	}
	else if (!ft_strcmp(args->stack[0][0], "env"))
	{
		while (args->envp[++i])
			printf("%s\n", args->envp[i]);
		return (1);
	}
	else if (!ft_strcmp(args->stack[0][0], "exit"))
		ft_exit(args);
	return (0);
}
