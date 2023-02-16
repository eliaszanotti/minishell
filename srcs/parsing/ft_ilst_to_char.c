/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilst_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:49:15 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/16 17:49:29 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_ilst_to_char(t_ilst *str)
{
	t_ilst	*tmp;
	char	*new_str;
	int		size;

	size = ft_ilstsize(str);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	size = 0;
	while (str)
	{
		new_str[size++] = str->content;
		tmp = str->next;
		free(str);
		str = tmp;
	}
	new_str[size] = '\0';
	return (new_str);
}
