/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:39 by elias             #+#    #+#             */
/*   Updated: 2023/06/20 19:09:53 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_get_instruction(t_list *instruction)
{
	char	**char_instruction;
	int		size;

	size = ft_lstsize(instruction) + 1;
	char_instruction = malloc(sizeof(char *) * size);
	if (!char_instruction)
		return (NULL);
	size = 0;
	while (instruction)
	{
		char_instruction[size++] = ft_strdup(instruction->content);
		instruction = instruction->next;
	}
	char_instruction[size] = NULL;
	return (char_instruction);
}

static t_list	*ft_execute_loop(t_args *args, t_list *stack)
{
	char	**instruction;
	t_list	*current;
	int		count;

	current = stack;
	count = 0;
	while (current && count < args->size - 1)
	{
		if (ft_is_redirect(current->content) && \
			ft_redirect(current->content, args))
			return (NULL);
		else if (!ft_is_delimiter(current->content))
		{
			instruction = ft_get_instruction(current->content);
			if (!instruction)
				return (NULL);
			if (ft_child_execution(args, instruction, 0))
				return (ft_free_str(instruction), NULL);
			ft_free_str(instruction);
			count++;
		}
		current = current->next;
	}
	return (current);
}

static int	ft_execute_command(t_args *args)
{
	char	**instruction;
	t_list	*stack;

	stack = ft_execute_loop(args, args->stack);
	if (!stack)
		return (1);
	if (ft_is_delimiter(stack->content) == '|')
		stack = stack->next;
	while (stack && ft_is_redirect(stack->content))
	{
		if (ft_redirect(stack->content, args))
			return (1);
		stack = stack->next;
	}
	if (!stack)
		return (0);
	instruction = ft_get_instruction(stack->content);
	if (!instruction)
		return (ft_error(99, NULL));
	if (stack && ft_child_execution(args, instruction, 1))
		return (ft_free_str(instruction), 1);
	return (ft_free_str(instruction), 0);
}

int	ft_exec(t_args *args)
{
	t_list	*stack;
	int		i;

	stack = args->stack;
	i = -1;
	while (stack)
	{
		if (!ft_is_delimiter(stack->content))
			args->size++;
		stack = stack->next;
	}
	i = 0;
	args->pid_tab = malloc(sizeof(pid_t) * args->size);
	if (!args->pid_tab)
		return (ft_error(99, NULL));
	args->close_tab = malloc(sizeof(int) * args->size);
	if (!args->close_tab)
		return (ft_error(99, NULL));
	while (i < args->size)
		args->pid_tab[i++] = 0;
	args->fdd = 0;
	if (ft_execute_command(args))
		return (free(args->close_tab), free(args->pid_tab), 1);
	return (ft_wait_execution(args));
}
