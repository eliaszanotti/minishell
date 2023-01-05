/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:07 by elias             #+#    #+#             */
/*   Updated: 2023/01/05 11:31:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_delimiter(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "<") || !ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}
