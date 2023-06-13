/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:10:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 14:11:13 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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