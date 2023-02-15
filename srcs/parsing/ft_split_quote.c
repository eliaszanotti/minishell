/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/15 16:24:56 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

#include <stdio.h>
void	ft_lll(t_list *lst)
{
	printf("--log--\n");
	while (lst)
	{
		printf("str = [%s]\n", (char *)lst->content);
		lst = lst->next;
	}
	printf("--end--\n\n");
}

t_list	*ft_split_pipe(char *str)
{
	t_list	*splt_pipe;

	splt_pipe = NULL;
	while (*str)
	{
		str = ft_skip_redirect(&splt_pipe, str);
		if (!str)
			return (NULL);
		str = ft_skip_alpha(&splt_pipe, str);
		if (!str)
			return (NULL);
		str = ft_skip_pipe(&splt_pipe, str);
		if (!str)
			return (NULL);
		str = ft_skip_spaces(str);
	}
	ft_lll(splt_pipe);
	return (splt_pipe);
}

int	ft_split_quote(t_args *args, char *s)
{
	if (!s || !*s)
		return (0);
	if (ft_check_quotes(s))
		return (ft_error(3));
	args->cl = ft_split_pipe(s);
	if (!args->cl)
		return (ft_error(99));
	return (0);
}
