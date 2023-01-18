/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/18 14:09:48 by tgiraudo         ###   ########.fr       */
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

int	ft_execute_child(char **command, t_args *args)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(ft_get_path(command[0]), command, args->envp) == -1)
			printf("ERROR;\n"); //TODO 
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	//close(fd[0]);
	//close(fd[1]);
	return (0);
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
		while (args->instructions[i] && i < size - 1)
			ft_execute_child(args->instructions[i++], args);
	pid = fork();
	if (pid == 0)
		execve(ft_get_path(args->instructions[i][0]), args->instructions[i], \
			args->envp);
	waitpid(pid, NULL, 0);
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
	char	cwd[1024];
	char	*command;
	int		error_code;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_ignore);
	while (!args->exit_code)
	{
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd)));
		command = readline(args->prompt);
		//command = "< out | ls";
		add_history(command);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			ft_log(args->stack);
			if (args->stack[0])
				ft_execute_command(args);
		}
		//free(command);
		//return (0); //Temp for testing (uncommented while testing)
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
