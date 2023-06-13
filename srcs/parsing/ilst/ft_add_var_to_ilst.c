/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_var_to_ilst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:20:54 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 14:21:08 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_var_to_ilst(t_args *args, t_ilst **str, char *name)
{
	t_ilst	*new;
	char	*value;
	int		i;

	value = ft_getenv(args, name);
	if (!value)
		return (0);
	i = -1;
	while (value[++i])
	{
		new = ft_ilstnew(value[i]);
		if (!new)
			return (ft_error(99));
		ft_ilstadd_back(str, new);
	}
	free(value);
	return (0);
}