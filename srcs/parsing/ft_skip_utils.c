/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:19:51 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/15 16:20:50 by ezanotti         ###   ########.fr       */
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

char	*ft_skip_redirect(t_list **splt_pipe, char *str)
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
		new = ft_lstnew(ft_substr(str, 0, i));
		if (!new)
			return (NULL);
		ft_lstadd_back(splt_pipe, new);
		return (str + i);
	}
	return (str);
}

char	*ft_skip_alpha(t_list **splt_pipe, char *str)
{
	t_list	*new;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '|' && str[i] != '<' && \
		str[i] != '>')
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
		ft_lstadd_back(splt_pipe, new);
	}
	return (str + i);
}

char	*ft_skip_pipe(t_list **splt_pipe, char *str)
{
	t_list	*new;

	if (*str == '|')
	{
		new = ft_lstnew(ft_strdup("|"));
		if (!new)
			return (NULL);
		ft_lstadd_back(splt_pipe, new);
		return (str + 1);
	}
	return (str);
}

char	*ft_skip_spaces(char *str)
{
	while (*str && *str == ' ')
		str++;
	return (str);
}
