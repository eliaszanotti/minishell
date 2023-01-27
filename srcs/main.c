/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/27 20:11:49 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_log(char ***stack)
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

static int	ft_prompt_loop(t_args *args)
{
	char	cwd[PATH_MAX];
	char	*command;
	int		error_code;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_ignore);
	while (!args->exit_code)
	{
		ft_reset_struct(args);
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd))); // TODO move dans reset struct
		command = readline(args->prompt);
		free(args->prompt);
		//command = "";
		if (!command)
			ft_exit(args);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			ft_log(args->stack);
			add_history(command);
			if (ft_start_execution(args) == 99)
				return (ft_free_args(args), 1);
			ft_free_args(args);
		}
		free(command);
		//return (0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	(void)argc;
	(void)argv;
	if (ft_struct_init(&args))
		return (1);
	args.envp = envp;
	return (ft_prompt_loop(&args));
}
