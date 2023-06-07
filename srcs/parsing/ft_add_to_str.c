/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:02:02 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/07 12:48:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_char(t_ilst **str, char *content)
{
	t_ilst	*new;

	if (*content == '\'' || *content == '"')
		return (content);
	if (*content)
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
			if (*content != '"' && *content != '$')
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
