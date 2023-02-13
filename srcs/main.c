/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/02/13 18:23:58 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_log2(char ***stack)
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
	char	*command;
	int		error_code;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_ignore);
	while (!args->exit_code)
	{
		ft_reset_struct(args);
		command = readline(args->prompt);
		free(args->prompt);
		//command = "cd l";
		if (!command)
			ft_exit(args);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			add_history(command);
			if (ft_start_execution(args) == 99)
				return (ft_free_envp(args), 1);
			ft_free_instruction(args->cl);
			ft_free_stack(args->stack);
		}
		free(command);
		//return (ft_free_envp(args), 0);
	}
	return (ft_free_envp(args), 0);
}

//TODO error quand command = "srcs" et apres "exit"

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	(void)argc;
	(void)argv;
	if (ft_struct_init(&args, envp))
		return (1);
	if (ft_prompt_loop(&args))
		return (1);
	return (0);
}
