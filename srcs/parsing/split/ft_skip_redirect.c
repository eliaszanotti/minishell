/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:44:54 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 13:45:37 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_skip_redirect(t_list **instruction, char *str)
{
	t_list	*new;
	char	redirect;
	int		i;

	i = 0;
	if (str[i] == '<' || str[i] == '>')
	{
		redirect = str[i++];
		if (str[i] == redirect)
			i++;
	}
	if (i)
	{
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
		new = ft_lstnew(ft_substr(str, 0, i));
		if (!new)
			return (NULL);
		ft_lstadd_back(instruction, new);
		if (ft_add_single_str(instruction, NULL))
			return (NULL);
	}
	return (str + i);
}