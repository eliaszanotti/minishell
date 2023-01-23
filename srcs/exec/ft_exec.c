/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:39 by elias             #+#    #+#             */
/*   Updated: 2023/01/23 13:36:38 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_execute_child(t_args *args, char **command, int last)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd))
		return (ft_error(4));
	pid = fork();
	if (pid == -1) 
		return (ft_error(4));
	else if (pid == 0) 
	{
		if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
			return (ft_error(6));
		else if (dup2(args->fdd, STDIN_FILENO) == -1)
			return (ft_error(6));
		if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
			return (ft_error(6));
		if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
			return (ft_error(6));
		close(fd[0]);
		if (execve(ft_get_path(command[0]), command, args->envp) == -1)
			return (ft_error(5));
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (0);
}

int	ft_execute_command(t_args *args, int size)
{
	int	count;
	int i;
	args->fdd = 0;

	count = 0;
	i = -1;
	while (args->stack[++i] && count < size - 1)
	{
		if (!ft_get_path(args->stack[i][0]) && \
			ft_is_delimiter(args->stack[i][0]) != '|' && \
			ft_redirect(args->stack[i], args))
			return (1);
		else if (ft_get_path(args->stack[i][0]))
		{
			if (ft_execute_child(args, args->stack[i], 0))
				return (1);
			count++;
		}
	}
	if (ft_is_delimiter(args->stack[i][0]) == '|')
		i++;
	while (!ft_get_path(args->stack[i][0]) && \
		ft_is_delimiter(args->stack[i][0]) != '|')
		if (ft_redirect(args->stack[i++], args))
			return (1);
	if (ft_execute_child(args, args->stack[i], 1))
		return (1);
	return (0);
}

int	ft_start_execution(t_args *args)
{
	//pid_t	pid;
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (args->stack[i])
		if (ft_get_path(args->stack[i++][0]))
			size++;
	//if (size >= 2)
	return (ft_execute_command(args, size));
	/*else
	{
		if (!ft_exec_builtins(args))
		{
			ft_redirect(args->stack[i], args);
			if (args->stack[i + 1])
				ft_redirect(args->stack[i + 1], args);
			pid = fork();
			if (pid == 0)
			{
					dup2(args->infile, STDIN_FILENO);
					dup2(args->outfile, STDOUT_FILENO);
				printf("outfile : %d\n", args->outfile);
				execve(ft_get_path(args->instructions[0][0]), args->instructions[0], args->envp); // TODO create exec function
			}
			waitpid(pid, NULL, 0);
			args->infile = 0;
			args->outfile = 1;
		}
	}*/
}

