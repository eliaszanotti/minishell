/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 16:42:54 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_command_list(t_list *instruction)
{
	char	**command_list;
	int		size;

	size = ft_lstsize(instruction) + 1;
	command_list = malloc(sizeof(char *) * size);
	if (!command_list)
		return (NULL);
	size = 0;
	while (instruction)
	{
		command_list[size++] = instruction->content;
		instruction = instruction->next;
	}
	command_list[size] = NULL;
	return (command_list);
}

char	*ft_is_b(t_list *instruction)
{
	char	*cmd;

	cmd = instruction->content;
	if (!ft_strcmp(cmd, "echo"))
		return ("echo");
	else if (!ft_strcmp(cmd, "cd"))
		return ("cd");
	else if (!ft_strcmp(cmd, "pwd"))
		return ("pwd");
	else if (!ft_strcmp(cmd, "export"))
		return ("export");
	else if (!ft_strcmp(cmd, "unset"))
		return ("unset");
	else if (!ft_strcmp(cmd, "env"))
		return ("env");
	else if (!ft_strcmp(cmd, "exit"))
		return ("exit");
	return (NULL);
}

char	ft_is_d(t_list *instruction)
{
	char	*str;

	str = instruction->content;
	if (!ft_strcmp(str, "|"))
		return ('|');
	if (!ft_strcmp(str, "<"))
		return ('<');
	if (!ft_strcmp(str, ">"))
		return ('>');
	if (!ft_strcmp(str, "<<"))
		return ('l');
	if (!ft_strcmp(str, ">>"))
		return ('r');
	return (0);
}

char	ft_is_r(t_list *instruction)
{
	if (ft_is_d(instruction) && ft_is_d(instruction) != '|')
		return (ft_is_d(instruction));
	return (0);
}

int	ft_check_parsing(t_args *args)
{
	t_list	*cl;

	cl = args->cl;
	if (!cl)
		return (1);
	if (ft_is_d(cl) == '|')
		return (ft_error(4));
	while (cl)
	{
		if (ft_is_d(cl) && !cl->next)
			return (ft_error(6));
		if (ft_is_d(cl) == '|' && cl->next)
			if (ft_is_d(cl->next) == '|')
				return (ft_error(4));
		if (ft_is_r(cl) && cl->next)
			if (ft_is_d(cl->next))
				return (ft_error(5));
		cl = cl->next;
	}
	printf("ook\n\n");
	return (0);
}

int	ft_check_command(t_args *args)
{
	t_list	*stack;
	t_list	*tmp;

	stack = args->stack_list;
	while (stack)
	{
		tmp = stack->content;
		if (tmp && (!ft_is_delimiter(tmp->content) && \
			!ft_is_command(args, tmp->content) && \
			!ft_is_builtins(tmp->content)))
			return (ft_error(2));
		stack = stack->next;
	}
	return (0);
}
