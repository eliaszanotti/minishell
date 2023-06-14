/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:15:31 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 14:24:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_error(char *str)
{
	char	*new_str;

	new_str = ft_strjoin("\e[1;31m[ERROR]\e[0m ", str);
	if (!new_str)
		return (1);
	write(STDERR_FILENO, new_str, ft_strlen(new_str));
	free(new_str);
	return (1);
}
