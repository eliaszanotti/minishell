/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/15 16:34:18 by ezanotti         ###   ########.fr       */
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

int	ft_split_quote(t_args *args, char *str)
{
	if (!str || !*str)
		return (0);
	if (ft_check_quotes(str))
		return (ft_error(3));
	args->cl = NULL;
	while (*str)
	{
		str = ft_skip_redirect(&args->cl, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_alpha(&args->cl, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_pipe(&args->cl, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_spaces(str);
	}
	ft_lll(args->cl);
	return (0);
}
