/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_single.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:09:45 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:23:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
