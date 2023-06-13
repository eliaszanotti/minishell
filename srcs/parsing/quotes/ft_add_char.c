/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:09:04 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:23:40 by elias            ###   ########.fr       */
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
