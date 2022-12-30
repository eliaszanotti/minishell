/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/30 14:58:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>

int	ft_is_delimiter(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "<") || !ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

int	ft_get_instructions(t_args *args)
{
	char	*good_path;
	int i; 

	i = 0;
	while (args->command_list[i])
		i++;
	args->instructions = malloc(sizeof(char *) * (i + 1));
	if (!args->instructions)
		return (99);
	i = 0;
	while (args->command_list[i])
	{
		good_path = ft_get_path(args->envp, args->command_list[i]);
		if (good_path)
			args->instructions[i] = good_path;
		else
			args->instructions[i] = args->command_list[i];
		i++;
	}
	args->instructions[i] = NULL;
	return (0);
}

int	ft_execute_command(t_args *args)
{
	char	**current_command;
	int		i;
	int		size;
	int	fd[2]; //TODO : fd[size of number of pipes] (ex: fd[5] for 4 pipes)

	ft_get_instructions(args);
	
	if (pipe(fd) == 1)
		return (1);

	pid_t pid;
	//pid_t pid2;

	char	***big = malloc(sizeof(char **) * 3);
	big[2] = NULL;

	int count = 0;


	while (*args->instructions && access(*args->instructions, F_OK) == 0)
	{
		i = 0;
		if (access(args->instructions[i], F_OK) == 0)
			while (args->instructions[i] \
					&& !ft_is_delimiter(args->instructions[i]))
				i++;
		current_command = malloc(sizeof(char *) * (i + 1));
		if (!current_command)
			return (99);
		size = i;
		current_command[i] = NULL;
		while (--i >= 0 && args->instructions[i])
			current_command[i] = ft_strdup(args->instructions[i]);
		
		args->instructions += size;
		if (*args->instructions)
			args->instructions++;


		big[count] = current_command;
	
		pid = fork();
		if (pid == 0)
		{
			close(fd[2 - count - 1]);
			dup2(fd[count], count);
			execve(big[count][0], big[count], NULL);
				


		}
	



		count++;
	}

	/*pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		execve(big[1][0], big[1], NULL);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(big[0][0], big[0], NULL);
	}*/


	/*count = 0;
	while (big[count])
		printf("%s\n", big[count++][0]);*/

	/*int count = 0;
	while (current_command[count])
	{
		printf("%s\n", current_command[count]);
		free(current_command[count]);
		count++;
	}*/

	(void)args;
	//TODO
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	*command;
	int		error_code;

	while (!args->exit_code)
	{
		usleep(100000);
		command = readline(args->prompt);
		args->command_list = ft_split(command, ' ');
		error_code = ft_execute_command(args);
		if (error_code)
			return (error_code);
		if (args->command_list[0] && \
				!ft_strcmp(args->command_list[0], "exit"))
			args->exit_code = 1;
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
