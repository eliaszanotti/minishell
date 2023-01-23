/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/23 13:43:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_log(char ***stack)
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

int    ft_reset_struct(t_args *args) // TODO move dan struct
{
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	cwd[PATH_MAX];
	char	*command;
	int		error_code;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_ignore);
	while (!args->exit_code)
	{
		ft_reset_struct(args);
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd)));
		command = readline(args->prompt);
		//command = "rm out";
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			ft_log(args->stack);
			if (args->stack[0])
			{
				add_history(command);
				ft_start_execution(args);
			}
		}
		else 
			ft_error(error_code);
		//return (0);
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
