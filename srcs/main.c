/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2023/02/16 18:28:08 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_log2(char ***stack)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (stack[++i])
	{
		j = 0;
		while (stack[i][j])
			printf("[%s]", stack[i][j++]);
		printf("\n");
	}
}

#include <stdio.h> // TODO  temp
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
}

static int	ft_prompt_loop(t_args *args, char *c)
{
	char	*command;
	int		error_code;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sig_ignore);
	while (!args->exit_code)
	{
		ft_reset_struct(args);
		if (c)
			command = "echo \"fejfjnen\"'$EDITOR'\"ntjh\"";
		else
			command = readline(args->prompt);
		free(args->prompt);
		if (!command)
			ft_exit(args);
		error_code = ft_parse_args(args, command);
		if (!error_code)
		{
			//ft_log(args->stack);
			add_history(command);
			if (ft_start_execution(args) == 99)
				return (ft_free_envp(args), 1);
			//ft_free_instruction(args->cl);
			ft_free_stack(args->stack);
			errno = 0; // TODO peutetre a deplacer
		}
		//printf("errno == %d\n", errno); // TODO gerer les erreurs 
		if (c)
			return (ft_free_envp(args), 1);
		free(command);
	}
	return (ft_free_envp(args), 0);
}

//TODO error quand command = "srcs" et apres "exit"

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	(void)argc;
	(void)argv;
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
		return (1);
	}
	return (errno);
}
