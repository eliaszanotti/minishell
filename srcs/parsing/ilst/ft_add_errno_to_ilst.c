/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_errno_to_ilst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:21:18 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:24:06 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_errno_to_ilst(t_args *args, t_ilst **str, char *content)
{
	t_ilst	*new;
	char	*error;
	int		i;

	(void)args;
	error = ft_itoa(g_last_errno);
	if (!error)
		return (NULL);
	i = -1;
	while (error[++i])
	{
		new = ft_ilstnew(error[i]);
		if (!new)
			return (NULL);
		ft_ilstadd_back(str, new);
	}
	free(error);
	return (content + 1);
}
