/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:11:19 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:23:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_tilde(t_args *args, t_ilst **str, char *content)
{
	if (*content == '~')
	{
		if (*(content + 1) != '/' && *(content + 1) != ' ' && *(content + 1))
			return (content);
		if (ft_add_var_to_ilst(args, str, "HOME"))
			return (NULL);
		return (content + 1);
	}
	return (content);
}
