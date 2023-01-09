/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/09 14:48:10 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_cmd(t_args *args)
{
	int i;

	i = -1;
	if (!ft_strcmp(args->stack[0][0], "echo"))
	{
		ft_echo(args->stack[0]);
		return (1);
	}
	else if (!ft_strcmp(args->stack[0][0], "cd"))
	{
       ft_open_dir(args->stack[0]);
	   return (1);
	}
	else if (!ft_strcmp(args->stack[0][0], "pwd"))
	{
		printf("%s\n", getenv("PWD"));
		return (1);
	}
	else if (!ft_strcmp(args->stack[0][0], "env"))
	{
		while (args->envp[++i])
			printf("%s\n", args->envp[i]);
		return (1);
	}
	else if (!ft_strcmp(args->stack[0][0], "exit"))
	{
		printf("OK");
		ft_exit(args);
	}
	return (0);
}

void	ft_open_dir(char **cmd)
{
	chdir(cmd[1]);
}

void	ft_echo(char **cmd)
{
	int i;
	
	i = 1;
	if (!ft_strcmp(cmd[1], "-n"))
	{
		while(cmd[++i])
		{
			cmd[i] = ft_remove_quotes(cmd[i]);
			printf("%s ", cmd[i]);
		}
		printf("%%");
	}
	else
	{
		while(cmd[i])
		{
			cmd[i] = ft_remove_quotes(cmd[i]);
			printf("%s ", cmd[i++]);
		}
	}
	printf("\n");
}
