/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/18 18:47:30 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>
#include <fcntl.h>

void	ft_log(char ***stack)
{
	int	i = -1;
	int	j = 0;

	while (stack[++i])
	{
		j = 0;
		while (stack[i][j])
			printf("[%s]", stack[i][j++]);
		printf("\n");
	}
}

 /*int	ft_execute_child(char **command, t_args *args)
 {
 	pid_t	pid;
 	int		fd[2];

 	pipe(fd);
 	pid = fork();
 	if (pid == 0)
 	{
 		if (dup2(fd[1], STDOUT_FILENO) == -1)
 			printf("ERROR;\n");
 		close(fd[0]);
 		close(fd[1]);
		if (execve(ft_get_path(command[0]), command, args->envp) == -1)
	 		printf("ERROR;\n"); //TODO
 	}
 	else
 	{
 		if (dup2(fd[0], STDIN_FILENO) == -1)
 			printf("ERROR;\n");
 		close(fd[0]);
 		close(fd[1]);
 	}
 	close(fd[1]);
 	close(fd[0]);
 	// waitpid(pid, NULL, 0);
 	return (0);
}*/


int ft_test(t_args *args, char **command, int last, int fdd)
{
	int fd[2];
	pid_t pid;
	
	pipe(fd);
	if ((pid = fork()) == -1) 
		return (-1);
	else if (pid == 0) 
	{
		dup2(fdd, STDIN_FILENO);
		if (!last)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execve(ft_get_path(command[0]), command, args->envp);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return (fd[0]);
}	

int	ft_execute_child(t_args *args, char ***cmd, int size)
{
	int i;
	int fdd;

	i = 0;
	fdd = 0;
	while (cmd[i] && i < size - 1)
		fdd = ft_test(args, cmd[i++], 0, fdd);
	fdd = ft_test(args, cmd[i], 1, fdd);
	return (0);
}

int	ft_execute_command(t_args *args)
{
	pid_t	pid;
	int		size;

	size = 0;
	while (args->instructions[size])
		size++;
	if (size >= 2)
		ft_execute_child(args, args->instructions, size);
	else
	{
		pid = fork();
		if (pid == 0)
			execve(ft_get_path(args->instructions[0][0]), args->instructions[0], args->envp);	
		waitpid(pid, NULL, 0);
	}
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	cwd[PATH_MAX];
	char	*command;
	int		error_code;

	while (!args->exit_code)
	{
		signal(3, SIG_IGN);
		//signal(2, SIG_IGN); //TODO
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd)));
		command = readline(args->prompt);
		//command = "ls | grep RE | wc";
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			ft_log(args->stack);
			if (args->stack[0])
			{
				add_history(command);
				ft_execute_command(args);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	int		error_code;

	error_code = ft_struct_init(&args);
	if (error_code)
		return (ft_error(error_code));
	args.envp = envp;
	error_code = ft_prompt_loop(&args);
	if (error_code)
		return (ft_error(error_code));
	(void)argc;
	(void)argv;
	return (0);
}
