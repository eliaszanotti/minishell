/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:08:14 by elias             #+#    #+#             */
/*   Updated: 2023/06/21 10:21:02 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_single_ilst(t_ilst **str, char content)
{
	t_ilst	*new;

	new = ft_ilstnew(content);
	if (!new)
		return (ft_error(99, NULL));
	ft_ilstadd_back(str, new);
	return (0);
}

static char	*ft_check_special_case(t_args *args, t_ilst **str, char *content)
{
	if ((!*content || ft_strchr("$=+ \"", *content)) && \
	ft_add_single_ilst(str, '$'))
		return (content);
	if (*content == '?')
		return (ft_add_errno_to_ilst(args, str, content));
	return (content);
}

char	*ft_add_variable(t_args *args, t_ilst **str, char *content)
{
	char	*name;
	int		i;

	i = 0;
	content = ft_add_tilde(args, str, content);
	if (!content)
		return (NULL);
	if (*content == '$')
	{
		content = ft_check_special_case(args, str, content + 1);
		while (content[i] && ft_is_variable(content[i]))
			i++;
		if (!i)
			return (content);
		name = ft_substr(content, 0, i);
		if (!name)
			return (NULL);
		if (ft_add_var_to_ilst(args, str, name))
			return (free(name), NULL);
		free(name);
	}
	return (content + i);
}
