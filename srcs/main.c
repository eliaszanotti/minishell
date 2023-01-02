/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event02 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:11:54 by event02           #+#    #+#             */
/*   Updated: 2023/01/02 19:10:05 by event02          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/02 18:11:31 by event02          ###   ########lyon.fr   */
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

/*while (*args->instructions && !access(*args->instructions, F_OK))
{ 
	printf("%d\n", !ft_is_delimiter(args->instructions[i]));
	while (args->instructions[i] \
			&& !ft_is_delimiter(args->instructions[i]))
		i++;
	*args->instructions += i;
	if (*args->instructions)
		args->instructions += 1;
}*/

void	ft_log(char ***stack)
{
	int i = 0;
	int j = 0;
	while (stack[i])
	{
		j = 0;
		while (stack[i][j])
		{
			printf("[%s]", stack[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	ft_parse_command_list(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args->command_list[i])
	{
		if (!ft_strcmp(args->command_list[i], "\""))
		{
			j = i + 1;
			while (args->command_list[j] && ft_strcmp(args->command_list[j], "\""))
				j++;
			if (!args->command_list[j])
				return (100); // replace by parse error (100 is temp value)
			printf("i = %d, j = %d\n", i, j);
			i = j;
		}
		i++;



		

	}

	return (0);
}


int	ft_execute_command(t_args *args)
{
	int		error_code;

	ft_parse_command_list(args);
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
	(void)args;
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	*command;
	int		error_code;

	pid_t pid;

	while (!args->exit_code)
	{
		command = readline(args->prompt);
		//command = "ls | rg2 ls \" || kill  > ls  \" |  whoami";
		args->command_list = ft_split_quote(command, ' ');
		error_code = ft_execute_command(args);
		if (error_code)
			return (error_code);
		pid = fork();
		if (pid == 0)
			execve(ft_get_path(args->envp, args->stack[0][0]), args->stack[0], args->envp);
		waitpid(pid, NULL, 0);
		//return (0); //Temp for testing
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
