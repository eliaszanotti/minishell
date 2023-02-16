/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/02/16 16:40:15 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_new_content(t_ilst *str)
{
	t_ilst	*tmp;
	char	*new_str;
	int		size;

	size = ft_ilstsize(str);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	size = 0;
	while (str)
	{
		new_str[size++] = str->content;
		tmp = str->next;
		free(str);
		str = tmp;
	}
	new_str[size] = '\0';
	return (new_str);
}

int	ft_add_var_to_ilst(t_args *args, t_ilst **str, char *name)
{
	t_ilst	*new;
	char	*value;
	int		i;

	value = ft_getenv(args, name);
	if (!value)
		return (free(name), 0);
	i = -1;
	printf("value == %s\n", value);
	while (value[++i])
	{
		new = ft_ilstnew(value[i]);
		if (!new)
			return (ft_error(99));
		ft_ilstadd_back(str, new);
	}
	return (0);
}

char	*ft_add_errno_to_ilst(t_ilst **str, char *content)
{
	t_ilst	*new;
	char	*error;
	int		i;

	error = ft_itoa(errno);
	if (!error)
		return (NULL);
	i = -1;
	while (error[++i])
	{
		new = ft_ilstnew(error[i]);
		if (!new)
			return (NULL);
		ft_ilstadd_back(str, new);
	}
	free(error);
	return (content + 1);
}

char	*ft_skip_variable(t_args *args, t_ilst **str, char *content)
{
	char	*name;
	int		i;
	
	i = 0;
	if (*content == '$')
	{
		content++;
		if (*content == '?')
			return (ft_add_errno_to_ilst(str, content));
		while (content[i] && ft_is_variable(content[i]))
			i++;
		if (i)
		{
			name = ft_substr(content, 0, i);
			if (!name)
				return (NULL);
			if (ft_add_var_to_ilst(args, str, name))
				return (NULL);
			return (content + i);
		}
		// TODO add skip single ' qui ajoute a la liste jusqua retrouver '
	}
	return (content);
}

char	*ft_skip_char(t_ilst **str, char *content)
{
	t_ilst	*new;

	if (*content != '$')
	{
		new = ft_ilstnew(*content);
		if (!new)
			return (NULL);
		ft_ilstadd_back(str, new);
		return (content + 1);
	}
	return (content);
}

char	*ft_replace_env2(t_args *args, t_list *instruction)
{
	t_ilst	*str;
	char	*content;

	str = NULL;
	content = instruction->content;
	while (*content)
	{
		content = ft_skip_char(&str, content);
		if (!content)
			return (NULL);
		content = ft_skip_variable(args, &str, content);
		if (!content)
			return (NULL);
	}
	return (ft_get_new_content(str));
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
			//if (content[0] != '\'' && content[ft_strlen(content)] != '\'')
			content = ft_replace_env2(args, instruction);
			if (!content)
				return (ft_error(99));
			//content = ft_remove_quote(content);
			//if (!content)
			//	return (ft_error(99));
			instruction->content = content;
			instruction = instruction->next;
		}
		stack = stack->next;
	}
	return (0);
}
