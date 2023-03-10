/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_ilst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:52:31 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/27 15:39:07 by ezanotti         ###   ########.fr       */
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

char	*ft_add_errno_to_ilst(t_args *args, t_ilst **str, char *content)
{
	t_ilst	*new;
	char	*error;
	int		i;

	error = ft_itoa(args->last_err);
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
