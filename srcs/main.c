/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/13 17:01:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>
#include <fcntl.h>

void	ft_log(char ***stack)
{
	int	i = 0;
	int	j = 0;

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

int	ft_execute_child(char **command, t_args *args)
{
	int fd[2];
	pid_t	pid_child;

	pipe(fd);
	printf("%s\n", command[0]);
	pid_child = fork();
	if (pid_child == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(ft_get_path(command[0]), command, args->envp) == -1)
			printf("ERROR;\n");
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid_child, NULL, 0);
	}

	//close(fd[0]);
	//close(fd[1]);
	return (0);
}

int	ft_execute_command(t_args *args)
{
	//int	i;

	//i = 0;

	ft_execute_child(args->stack[0], args);
	ft_execute_child(args->stack[2], args);
	execve(ft_get_path(args->stack[4][0]), args->stack[4], args->envp);

	/*while (args->stack[i])
	{

		printf("\t%d\n", args->stack[i][0] != NULL);
		if (args->stack[i][0] && ft_get_path(args->stack[i][0]))
		{
			ft_execute_child(args->stack[i], args);
			i += 2;
		}
		else
			break;
	}*/
	//int file = open("out", O_WRONLY | O_CREAT | O_APPEND, 0777);
	//dup2(file, STDOUT_FILENO);
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	cwd[1024];
	char	*command;
	int		error_code;
	pid_t	pid;

	while (!args->exit_code)
	{
		signal(3, SIG_IGN);
		//signal(2, SIG_IGN); //TODO
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd)));
		command = readline(args->prompt);
		//command = "ls -l | wc | wc -l";
		//command = "ls | grep \"READ\"";
		add_history(command);
		//ft_get_delimiter(command, args);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			ft_log(args->stack);
			if (args->stack[0] != NULL)
			{
				if (args->stack[1] != NULL && !ft_strcmp(args->stack[1][0], "|"))
					ft_execute_command(args);
				else if (!ft_exec_builtins(args))
				{
					pid = fork();
					if (pid == 0)
						if (execve(ft_get_path(args->stack[0][0]), args->stack[0], NULL))
							return (11);
					waitpid(pid, NULL, 0);
				}
			}
		}
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
	(void)argc;
	(void)argv;
	return (0);
}
