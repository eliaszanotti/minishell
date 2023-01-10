/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/07 15:43:51 by event04          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>
#include <fcntl.h>

void	ft_log(char ***stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack[i])
	{
		j = 0;
		while (stack[i][j])
			printf("[%s]", stack[i][j++]);
		printf("\n");
		i++;
	}
}

void	ft_file_to_stdin(t_args *args, int *fd)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(34);
	close(fd[0]);
	if (execve(ft_get_path(args->stack[0][0]), args->stack[0], NULL) == -1)
		ft_error(1);
}

void	ft_stdout_to_file(t_args *args, int *fd)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(35);
	close(fd[1]);
	if (execve(ft_get_path(args->stack[2][0]), args->stack[2], NULL) == -1)
		ft_error(11);
}

int	ft_execute_command(t_args *args)
{
	int fd[2];
	int	pid_child;

	pipe(fd);
	pid_child = fork();
	if (pid_child == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		execve(ft_get_path(args->stack[0][0]), args->stack[0], args->envp);
	}
	printf("%d, %d\n", fd[1], fd[0]);
	//ft_fd(1);
	int	pid_parent;
	pid_parent = fork();
	if (pid_parent == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		execve(ft_get_path(args->stack[2][0]), args->stack[2], args->envp);
	}
	waitpid(pid_parent, NULL, 1);

	waitpid(pid_child, NULL, 0);
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	*command;
	int		error_code;
	//pid_t	pid;

	while (!args->exit_code)
	{
		signal(3, SIG_IGN);
		//signal(2, SIG_IGN); //TODO
		command = readline(args->prompt);
		//command = "ls | grep \"READ\""; //TODO "ls" dont work but ls is ok
		add_history(command);
		//ft_get_delimiter(command, args);
		error_code = ft_split_quote(args, command, ' ');
		if (!error_code)
		{
			error_code = ft_get_stack(args);
			if (error_code)
				return (error_code);
			ft_log(args->stack);
			ft_remove_quotes(args);
			ft_log(args->stack);
			ft_execute_command(args);
		}
		//ft_error(error_code);
		return (0); //Temp for testing (uncommented while testing)
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
	if (argc == 2)
		printf("%s", replace_env(argv[1]));
	return (0);
}



/*int	ft_execute_command(t_args *args)
{
	int	fd[2];
	int	pid_child;
	int	pid_parent;

	if (pipe(fd) == 1)
		return (1);
	pid_child = fork();
	if (pid_child < 0)
		return (1);
	if (pid_child == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error(34);
		close(fd[0]);
		if (execve(ft_get_path(args->stack[0][0]), args->stack[0], NULL) == -1)
			ft_error(1);
	}
	//	ft_file_to_stdin(args, fd);
	pid_parent = fork();
	if (pid_parent < 0)
		return (1);
	if (pid_parent == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error(35);
		close(fd[1]);
		if (execve(ft_get_path(args->stack[2][0]), args->stack[2], NULL) == -1)
			ft_error(11);
	}
	//	ft_stdout_to_file(args, fd);
	printf("END\n");
	waitpid(pid_child, NULL, 1);
	waitpid(pid_parent, NULL, 1);
	(void)args;
	return (0);
}*/
