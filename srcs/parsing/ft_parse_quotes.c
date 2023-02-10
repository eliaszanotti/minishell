/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/02/10 16:45:35 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_remove_quote(char *str)
{
	char	*new_str;
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (str[++i])
		if (str[i] == '\'' || str[i] == '"')
			size++;
	if (size == 0)
		return (str);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != '\'' && *str != '"')
			new_str[i++] = *str;
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_parse_quotes(t_args *args)
{
	t_list	*instruction;
	t_list	*stack;
	char	*content;

	stack = args->stack_list;
	while (stack)
	{
		instruction = stack->content;
		while (instruction)
		{
			content = instruction->content;
			if (content[0] != '\'' && content[ft_strlen(content)] != '\'')
				content = ft_replace_env(args, content);
			if (!content)
				return (ft_error(99));
			content = ft_remove_quote(content);
			if (!content)
				return (ft_error(99));
			instruction->content = content;
			instruction = instruction->next;
		}
		stack = stack->next;
	}
	return (0);
}
