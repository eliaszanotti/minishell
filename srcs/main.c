/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/04 19:12:01 by elias            ###   ########.fr       */
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

void ft_log_list(t_args *args)
{
	int i = 0;

	while (args->command_list[i])
		printf("%s\n", args->command_list[i++]);
}

int	ft_execute_command(t_args *args)
{
	int		error_code;

	error_code = ft_get_stack(args);
	if (error_code)
		return (error_code);
	ft_log(args->stack);
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
		//command = readline(args->prompt);
		command = "ls dejjfefjef | lk"; //TODO ERROR Malloc alors que non
		add_history(command);
		//ft_get_delimiter(command, args);
		error_code = ft_split_quote(args, command, ' ');
		ft_log_list(args);
		if (!error_code)
		{
			error_code = ft_execute_command(args);
			if (!error_code)
			{
				pid = fork();
				if (pid == 0)
					execve(ft_get_path(args->envp, args->stack[0][0]), args->stack[0], args->envp);
				waitpid(pid, NULL, 0);
				//free(command); //comment for testing
			}
		}
		ft_error(error_code);
		return (0); //Temp for testing (uncommented while testing)
	}
	return (0);
}

int	main(int argc, char **argv)
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
