/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:08:14 by elias             #+#    #+#             */
/*   Updated: 2023/06/06 16:45:47 by elias            ###   ########.fr       */
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

static int	ft_add_single_ilst(t_ilst **str, char content)
{
	t_ilst	*new;

	new = ft_ilstnew(content);
	if (!new)
		return  (ft_error(99));
	ft_ilstadd_back(str, new);
	return (0);
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
		content++;
		if (!*content && ft_add_single_ilst(str, '$'))
			return (content);
		if (*content == '?')
			return (ft_add_errno_to_ilst(args, str, content));
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