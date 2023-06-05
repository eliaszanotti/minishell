/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/06/05 18:59:44 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_replace_quotes(t_args *args, t_list *instruction)
{
	t_ilst	*str;
	char	*content;

	str = NULL;
	content = instruction->content;
	while (*content)
	{
		content = ft_add_single(&str, content);
		if (!content)
			return (NULL);
		content = ft_add_double(args, &str, content);
		if (!*content)
			break ;
		if (!content)
			return (NULL);
		content = ft_add_variable(args, &str, content);
		if (!content)
			return (NULL);
		content = ft_add_char(&str, content);
		if (!content)
			return (NULL);
	}
	return (ft_ilst_to_char(str));
}

int	ft_parse_quotes(t_args *args)
{
	t_list	*instruction;
	t_list	*stack;
	char	*content;

	stack = args->stack;
	while (stack)
	{
		instruction = stack->content;
		while (instruction)
		{
			content = ft_replace_quotes(args, instruction);
			if (!content)
				return (ft_error(99));
			instruction->content = content;
			instruction = instruction->next;
		}
		stack = stack->next;
	}
	return (0);
}
