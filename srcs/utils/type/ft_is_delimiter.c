/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_delimiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:04:16 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_is_delimiter(t_list *instruction)
{
	char	*str;

	str = instruction->content;
	if (!ft_strcmp(str, "|"))
		return ('|');
	if (!ft_strcmp(str, "<"))
		return ('<');
	if (!ft_strcmp(str, ">"))
		return ('>');
	if (!ft_strcmp(str, "<<"))
		return ('l');
	if (!ft_strcmp(str, ">>"))
		return ('r');
	return (0);
}
