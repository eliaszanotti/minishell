/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/18 17:46:58 by tgiraudo         ###   ########.fr       */
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

// int	ft_execute_child(char **command, t_args *args)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		if (dup2(fd[1], STDOUT_FILENO) == -1)
// 			printf("ERROR;\n");
// 		close(fd[0]);
// 		close(fd[1]);
// 		if (execve(ft_get_path(command[0]), command, args->envp) == -1)
// 			printf("ERROR;\n"); //TODO
// 	}
// 	else
// 	{
// 		if (dup2(fd[0], STDIN_FILENO) == -1)
// 			printf("ERROR;\n");
// 		close(fd[0]);
// 		close(fd[1]);
// 	}
// 	close(fd[1]);
// 	close(fd[0]);
// 	// waitpid(pid, NULL, 0);
// 	return (0);
// }

int	countPipes(char ***stack)
{
	int	i = -1;
	int	j = 0;
	int count = 0;

	while (stack[++i])
	{
		j = 0;
		while (stack[i][j])
			if (!ft_strcmp(stack[i][j], "|"))
				count++;
	}
	return (count);
}

void ft_execute_child(char ***cmd)
{
	int fd[2];
	pid_t pid;
	int i;
	int fdd = 0;				/* Backup */

	i = 0;
	while (cmd[i] != NULL) {
		pipe(fd);				/* Sharing bidiflow */
		if ((pid = fork()) == -1) {
			perror("fork");
			exit(1);
		}
		else if (pid == 0) {
			dup2(fdd, 0);
			if (cmd[i+1] != NULL) {
				dup2(fd[1], 1);
			}
			close(fd[0]);
			execve(ft_get_path(cmd[i][0]), cmd[i], NULL);
			exit(1);
		}
		else {
			wait(NULL); 		/* Collect childs */
			close(fd[1]);
			fdd = fd[0];
			i++;
		}
	}
}

int	ft_execute_command(t_args *args)
{
	pid_t	pid;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (args->instructions[size])
		size++;
	if (size >= 2)
	{
		ft_execute_child(args->instructions);
		return (0);		
	}
	pid = fork();
	if (pid == 0)
		execve(ft_get_path(args->instructions[size][0]), args->instructions[i], \
			args->envp);
	waitpid(pid, NULL, 0);
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	cwd[PATH_MAX];
	char	*command;
	int		error_code;
	int i = 0;

	printf("%d\n\n\n\n", STDOUT_FILENO);
	for (i = 0; i < 3; i++)
	{
		signal(3, SIG_IGN);
		//signal(2, SIG_IGN); //TODO
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd)));
		command = readline(args->prompt);
		// if (i == 0)
		// 	command = "ls | grep RE | wc";
		add_history(command);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			printf("lo\n");
			ft_log(args->stack);
			if (args->stack[0])
					ft_execute_command(args);
		}
		// return (0); //Temp for testing (uncommented while testing)
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
