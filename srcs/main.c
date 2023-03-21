/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/03/21 18:21:10 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_launch_execution(t_args *args, int error_code)
{
	if (!error_code)
	{
		if (ft_start_execution(args) == 99)
			return (ft_free_envp(args), 1);
		ft_free_instruction(args->command_list);
		ft_free_stack(args->stack);
		errno = 0;
	}
	return (0);
}

static int	ft_prompt_loop(t_args *args)
{
	char	*command;
	int		error_code;

	while (!args->exit_code)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ft_sig_ignore);
		ft_reset_struct(args);
		command = readline(args->prompt);
		free(args->prompt);
		if (!command)
		{
			printf("exit\n");
			return (0);
		}
		if (*command)
			add_history(command);
		error_code = ft_parse_args(args, command);
		if (ft_launch_execution(args, error_code))
			return (1);
		args->last_err = errno;
		free(command);
	}
	return (ft_free_envp(args), 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (ft_struct_init(&args, envp))
		return (1);
	ft_prompt_loop(&args);
	return (errno);
	(void)argc;
	(void)argv;
}
