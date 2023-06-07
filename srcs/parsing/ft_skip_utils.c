/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:19:51 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/07 14:55:20 by elias            ###   ########.fr       */
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

char	*ft_skip_redirect(t_list **instruction, char *str)
{
	t_list	*new;
	char	redirect;
	int		i;

	i = 0;
	if (str[i] == '<' || str[i] == '>')
	{
		redirect = str[i++];
		if (str[i] == redirect)
			i++;
	}
	if (i)
	{
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
		new = ft_lstnew(ft_substr(str, 0, i));
		if (!new)
			return (NULL);
		ft_lstadd_back(instruction, new);
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
	}
	return (str + i);
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

char	*ft_skip_pipe(t_list **instruction, char *str)
{
	t_list	*new;

	if (*str == '|')
	{
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
		new = ft_lstnew(ft_strdup("|"));
		if (!new)
			return (NULL);
		ft_lstadd_back(instruction, new);
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
		return (str + 1);
	}
	return (str);
}

char	*ft_skip_spaces(t_list **instruction, char *str)
{
	int	i;

	i = 0;
	while (*str && *str == ' ')
	{
		i = 1;
		str++;
	}
	if (i && *str && ft_add_single_str(instruction, NULL))
		return (NULL);
	return (str);
}
