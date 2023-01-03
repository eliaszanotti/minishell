/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/03 17:28:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>

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

int	ft_execute_command(t_args *args)
{
	int		error_code;

	error_code = ft_get_stack(args);
	if (error_code)
		return (error_code);
	ft_log(args->stack);
	
	//int	fd[2]; //TODO : fd[size of number of pipes] (ex: fd[5] for 4 pipes)
	/*if (pipe(fd) == 1)
		return (1);
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
	}*/
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	*command;
	int		error_code;
	pid_t	pid;

	while (!args->exit_code)
	{
		signal(3, SIG_IGN);
		//signal(2, SIG_IGN);//TODO
		command = readline(args->prompt);
		add_history(command);
		//command = "echo \" || kill '  > ls \"";
		error_code = ft_split_quote(args, command, ' ');
		if (!error_code)
		{
			error_code = ft_execute_command(args);
			if (!error_code)
			{
				pid = fork();
				if (pid == 0)
					execve(ft_get_path(args->envp, args->stack[0][0]), args->stack[0], args->envp);
				waitpid(pid, NULL, 0);
				free(command);
			}
		}
		ft_error(error_code);
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
