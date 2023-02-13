/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/02/13 17:56:54 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_init_new_str(char *str)
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
		return (ft_strdup(str));
	new_str = malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	return (new_str);
}

static char	*ft_remove_quote(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = ft_init_new_str(str);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != '\'' && str[j] != '"')
			new_str[i++] = str[j];
		j++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
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
