/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:02:02 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/16 18:31:27 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_variable(t_args *args, t_ilst **str, char *content)
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
	}
	return (content);
}

char	*ft_add_char(t_ilst **str, char *content)
{
	t_ilst	*new;

	if (*content == '\'' || *content == '"')
		return (content);
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

char	*ft_add_single(t_ilst **str, char *content)
{
	t_ilst	*new;

	if (*content == '\'')
	{
		content++;
		while (*content && *content != '\'')
		{
			new = ft_ilstnew(*content);
			if (!new)
				return (NULL);
			ft_ilstadd_back(str, new);
			content++;
		}
		if (*content == '\'')
			content++;
	}
	return (content);
}

char	*ft_add_double(t_args *args, t_ilst **str, char *content)
{
	t_ilst	*new;

	if (*content == '"')
	{
		content++;
		while (*content && *content != '"')
		{
			content = ft_add_variable(args, str, content);
			if (!content)
				return (NULL);
			if (*content != '"')
			{
				new = ft_ilstnew(*content);
				if (!new)
					return (NULL);
				ft_ilstadd_back(str, new);
				content++;
			}
		}
		if (*content == '"')
			return (content + 1);
	}
	return (content);
}
