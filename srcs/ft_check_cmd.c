/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/10 18:21:50 by tgiraudo         ###   ########.fr       */
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
		if (!ft_strcmp(args->stack[0][1], "~"))
			chdir(getenv("HOME"));
		else
			chdir(args->stack[0][1]);
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
		ft_exit(args);
		return (1);
	}
	return (0);
}

void	ft_echo(char **cmd)
{
	int	i;

	i = 1;
	if (!ft_strcmp(cmd[1], "-n"))
	{
		while (cmd[++i])
		{
			cmd[i] = ft_remove_quotes(cmd[i]);
			printf("%s ", cmd[i]);
		}
		printf("%%");
	}
	else
	{
		while (cmd[i])
		{
			cmd[i] = ft_remove_quotes(cmd[i]);
			printf("%s ", cmd[i++]);
		}
	}
	printf("\n");
}
