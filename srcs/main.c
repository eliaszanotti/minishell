/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/19 11:21:16 by tgiraudo         ###   ########.fr       */
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

/*int	ft_execute_command(t_args *args)
{
	pid_t	pid;
	int		max;
	int		count;
	int		i;

	max = 0;
	count = 0;
	i = 0;
	while (args->stack[i])
		if (ft_get_path(args->stack[i++][0]))
			max++;
	i = 0;
	printf("max : %d\n", max);
	while (args->stack[i])
	{
		if (count < max - 1 && ft_get_path(args->stack[i][0]))
		{
			ft_execute_child(args->stack[i], args);
			count++;
			printf("count : %d\n", count);
		}


		i++;
	}


	pid = fork();
	if (pid == 0)
		execve(ft_get_path(args->stack[i - 1][0]), args->stack[i - 1], \
			args->envp);
	waitpid(pid, NULL, 0);



	return (0);
}*/

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
		printf("infile : %d\n", args->infile);
		printf("outfile : %d\n", args->outfile);
		if (args->infile)
			dup2(args->infile, STDIN_FILENO);
		else
			dup2(fdd, STDIN_FILENO);
		if (!last)
			dup2(fd[1], STDOUT_FILENO);
		if (args->outfile)
			dup2(args->outfile, STDOUT_FILENO);
		close(fd[0]);
		execve(ft_get_path(command[0]), command, args->envp);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	args->infile = 0;
	args->outfile = 1;
	return (fd[0]);
}

void	redir(char **str, t_args *args)
{
	if (!ft_strcmp(str[0], "<"))
		args->infile = open(str[1], O_RDONLY);
	else if (!ft_strcmp(str[0], ">"))
		args->outfile = open(str[1], O_RDWR | O_TRUNC | O_CREAT, 0644);
}

int	ft_execute_child(t_args *args, char ***cmd, int size)
{
	int i;
	int fdd;

	i = 0;
	fdd = 0;
	printf("args->stack[i][0] : %s\n", args->stack[i][0]);
	while (cmd[i] && i < size - 1)
	{
		redir(args->stack[i], args);
		fdd = ft_test(args, cmd[i++], 0, fdd);
	}
	if (args->stack[i + 1])
		redir(args->stack[i + 1], args);
	fdd = ft_test(args, cmd[i], 1, fdd);
	return (0);
}

int	ft_execute_command(t_args *args)
{
	pid_t	pid;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (args->instructions[size])
		size++;
	if (size >= 2)
		ft_execute_child(args, args->instructions, size);
	else
	{
		if (!ft_exec_builtins(args))
		{
			redir(args->stack[i], args);
			if (args->stack[i + 1])
				redir(args->stack[i + 1], args);
			pid = fork();
			if (pid == 0)
			{
					dup2(args->infile, STDIN_FILENO);
					dup2(args->outfile, STDOUT_FILENO);
				printf("outfile : %d\n", args->outfile);
				execve(ft_get_path(args->instructions[0][0]), args->instructions[0], args->envp);
			}
			waitpid(pid, NULL, 0);
			args->infile = 0;
			args->outfile = 1;	
			printf("outfile2 : %d\n", args->outfile);
		}
	}
	return (0);
}

void	ft_sig_ignore(int sig)
{
	(void)sig;
	rl_on_new_line();
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_redisplay();
}

int	ft_prompt_loop(t_args *args)
{
	char	cwd[PATH_MAX];
	char	*command;
	int		error_code;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_ignore);
	while (!args->exit_code)
	{
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
