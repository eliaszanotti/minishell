/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:16 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/11 11:52:36 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_cmd(t_args *args)
{
	int	i;

	i = -1;
	if (!ft_strcmp(args->stack[0][0], "echo"))
		return (ft_echo(args->stack[0]));
	else if (!ft_strcmp(args->stack[0][0], "cd"))
		return (ft_open_dir(args->stack[0]));
	else if (!ft_strcmp(args->stack[0][0], "pwd"))
		return (printf("%s\n", getenv("PWD")));
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

int	ft_open_dir(char **cmd)
{
	if (!ft_strcmp(cmd[1], "~"))
	{
		if (chdir(getenv("HOME")) == -1)
			printf("cd: permission denied: %s\n", cmd[1]);
	}
	else
	{
		if (chdir(cmd[1]))
			printf("cd: permission denied: %s\n", cmd[1]);
	}
	return (1);
}

int	ft_echo(char **cmd)
{
	int	i;

	i = 1;
	if (!ft_strcmp(cmd[1], "-n"))
	{
		while (cmd[++i])
		{
			// cmd[i] = ft_remove_quotes(cmd[i]);
			printf("%s ", cmd[i]);
		}
		printf("%%");
	}
	else
	{
		while (cmd[i])
		{
			// cmd[i] = ft_remove_quotes(cmd[i]);
			printf("%s ", cmd[i++]);
		}
	}
	return (printf("\n"));
}
