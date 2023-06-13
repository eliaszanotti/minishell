/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:48:34 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 13:48:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_skip_spaces(t_list **instruction, char *str)
{
	int	i;

	i = 0;
	while (*str && *str == ' ')
	{
		i = 1;
		str++;
	}
	if (i && *str && ft_add_single_str(instruction, NULL))
		return (NULL);
	return (str);
}
