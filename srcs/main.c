/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/03/08 15:28:03 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_u(t_list *in)
{
	while (in)
	{
		printf("[%s]", (char *)in->content);
		in = in->next;
	}
	printf("\n");
}

void	ft_log(t_list *stack)
{
	while (stack)
	{
		ft_u(stack->content);
		stack = stack->next;
	}
	printf("%p\n", stack);
}

static int	ft_prompt_loop(t_args *args, char *c)
{
	char	*command;
	int		error_code;

	while (!args->exit_code)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ft_sig_ignore);
		ft_reset_struct(args);
		if (c)
			command = c;
		else
			command = readline(args->prompt);
		free(args->prompt);
		if (!command)
		{
			printf("exit\n");
			return (1);
		}
		if (*command)
			add_history(command);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			//ft_log(args->stack);
			if (ft_start_execution(args) == 99)
				return (ft_free_envp(args), 1);
			ft_free_instruction(args->command_list);
			ft_free_stack(args->stack);
			errno = 0; // TODO add condition
		}
		args->last_err = errno;
		if (c)
			return (ft_free_envp(args), 0);
		free(command);
	}
	return (ft_free_envp(args), 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	(void)argc;
	// TODO temp
	char *c;
	if (argc == 3)
		c = argv[2];
	else 
		c = NULL;


	if (ft_struct_init(&args, envp))
		return (1);
	if (ft_prompt_loop(&args, c))
	{
		exit(errno);
		return (errno);
	}
	exit(errno);
	return (errno);
}
