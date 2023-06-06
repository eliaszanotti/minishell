/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/06/06 16:17:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_errno;

static int	ft_launch_execution(t_args *args, int error_code)
{
	if (!error_code)
	{
		if (ft_start_execution(args) == 99)
			return (ft_free_envp(args), 1);
		ft_free_instruction(args->command_list);
		ft_free_stack(args->stack);
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
		// command = ft_strdup("echo $");
		free(args->prompt);
		if (!command)
		{
			printf("exit\n");
			return (ft_free_envp(args), 0);
		}
		if (*command)
			add_history(command);
		error_code = ft_parse_args(args, command);
		if (ft_launch_execution(args, error_code))
			return (1);
		free(command);
		// return (ft_free_envp(args), 0);
	}
	return (ft_free_envp(args), 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	g_last_errno = 0;
	if (ft_struct_init(&args, envp))
		return (1);
	ft_prompt_loop(&args);
	return (g_last_errno);
	(void)argc;
	(void)argv;
}
