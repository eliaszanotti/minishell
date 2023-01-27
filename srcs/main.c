/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/01/27 14:19:44 by elias            ###   ########.fr       */
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

void	ft_free_args3(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	free(args->prompt);
	while (args->command_list[i])
		free(args->command_list[i++]);
	free(args->command_list);
	i = 0;
	while (args->stack[i])
	{
		j = 0;
		while (args->stack[i][j])
			free(args->stack[i][j++]);
		free(args->stack[i++]);
	}
	free(args->stack);
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
		args->prompt = ft_get_prompt(getcwd(cwd, sizeof(cwd)));
		command = readline(args->prompt);
		//free(args->prompt);
		//command = "export ARG+=re";
		if (!command)
			ft_exit(args);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			ft_log(args->stack);
			add_history(command);
			ft_start_execution(args);
		}
		ft_free_args3(args);
		free(command);
		//return (0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;
	int		error_code;

	if (ft_struct_init(&args))
		return (1);
	args.envp = envp;
	error_code = ft_prompt_loop(&args);
	if (error_code)
		return (ft_error(error_code));
	(void)argc;
	(void)argv;
	return (0);
}
