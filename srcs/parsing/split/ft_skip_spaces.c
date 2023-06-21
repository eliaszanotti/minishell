/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:48:34 by elias             #+#    #+#             */
/*   Updated: 2023/06/21 16:15:50 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_skip_spaces(t_list **instruction, char *str)
{
	int	i;

	i = 0;
	while (*str && (*str == ' ' || *str == '\t'))
	{
		i = 1;
		str++;
	}
	if (i && *str && ft_add_single_str(instruction, NULL))
		return (NULL);
	return (str);
}
