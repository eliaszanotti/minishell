/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/13 14:45:35 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
void lll(t_list *test)
{
	char *str;
	while (test)
	{
		str = test->content;
		printf("OK = %s\n", str);
		test = test->next;
	}
}


static int	ft_get_i(char const *s, char c)
{
	char	quote;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
		}
		i++;
	}
	return (i);
}

t_list	*ft_splitstr(char const *s, char c)
{
	t_list	*instruction;
	t_list	*new;
	int		i;

	instruction = NULL;
	i = 0;
	while (*s)
	{
		i = ft_get_i(s, c);
		new = ft_lstnew(ft_substr(s, 0, i));
		if (!new)
			return (NULL); //TODO free
		ft_lstadd_back(&instruction, new);
		s += i;
		while (*s == c && *s)
			s++;
		i = 0;
	}
	return (instruction);
}

static int	ft_check_quotes(char *s)
{
	char	quote;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (!s[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_split_quote(t_args *args, char *s, char c)
{
	args->cl = NULL;
	if (!s || !*s)
		return (0);
	if (ft_check_quotes(s))
		return (ft_error(3));
	while (*s == c)
		s++;
	args->cl = ft_splitstr(s, c);
	if (!args->cl)
		return (ft_error(99));
	lll(args->cl);
	return (0);
}
