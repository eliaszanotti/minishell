/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:46:55 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 13:47:15 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_skip_pipe(t_list **instruction, char *str)
{
	t_list	*new;

	if (*str == '|')
	{
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
		new = ft_lstnew(ft_strdup("|"));
		if (!new)
			return (NULL);
		ft_lstadd_back(instruction, new);
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
		return (str + 1);
	}
	return (str);
}