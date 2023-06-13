/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:45:54 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:23:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_skip_quote(char *str, int i)
{
	char	quote;

	quote = str[i++];
	while (str[i] && str[i] != quote)
		i++;
	return (i);
}

char	*ft_skip_alpha(t_list **instruction, char *str)
{
	t_list	*new;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '<' && \
		str[i] != '>' && str[i] != '$')
	{
		if (str[i] == '"' || str[i] == '\'')
			i = ft_skip_quote(str, i);
		i++;
	}
	if (i)
	{
		new = ft_lstnew(ft_substr(str, 0, i));
		if (!new)
			return (NULL);
		ft_lstadd_back(instruction, new);
	}
	return (str + i);
}
