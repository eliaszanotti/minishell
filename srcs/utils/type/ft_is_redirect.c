/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:03:53 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_is_redirect(t_list *instruction)
{
	if (ft_is_delimiter(instruction) && ft_is_delimiter(instruction) != '|')
		return (ft_is_delimiter(instruction));
	return (0);
}
