/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_single_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:45:43 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 11:33:20 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_single_str(t_list **instruction, char *content)
{
	t_list	*new;
	char	*str;

	if (!content)
	{	
		new = ft_lstnew(NULL);
		if (!new)
			return (ft_error(99));
		ft_lstadd_back(instruction, new);
		return (0);
	}
	str = ft_strdup(content);
	if (!str)
		return (ft_error(99));
	new = ft_lstnew(str);
	if (!new)
		return (free(str), ft_error(99));
	ft_lstadd_back(instruction, new);
	return (0);
}
