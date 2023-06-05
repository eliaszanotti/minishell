/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:08:14 by elias             #+#    #+#             */
/*   Updated: 2023/06/05 19:11:31 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_add_tilde(t_args *args, t_ilst **str, char *content)
{
	if (*content == '~')
	{
		if (*(content + 1) != '/' && *(content + 1) != ' ' && *(content + 1))
			return (content);
		if (ft_add_var_to_ilst(args, str, "HOME"))
			return (NULL);
		return (content + 1);
	}
	return (content);
}

char	*ft_add_variable(t_args *args, t_ilst **str, char *content)
{
	int		i;
	t_ilst	*new;

	i = 0;
	content = ft_add_tilde(args, str, content);
	if (!content)
		return (NULL);
	if (*content == '$')
	{
		if (*(content + 1) == '?')
		{
			content++;
			return (ft_add_errno_to_ilst(args, str, content));
		}
		new = ft_ilstnew(*content);
		if (!new)
			return (NULL);
		ft_ilstadd_back(str, new);
		return (content + 1);
	}
	return (content + i);
}
