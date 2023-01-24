/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:27:22 by elias             #+#    #+#             */
/*   Updated: 2023/01/24 14:39:05 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect(char **str, t_args *args)
{
	if (ft_is_delimiter(str[0]) == '<')
		args->infile = open(str[1], O_RDONLY); 
	else if (ft_is_delimiter(str[0]) == '>')
		args->outfile = open(str[1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if (ft_is_delimiter(str[0]) == 'r')
		args->outfile = open(str[1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (args->infile == -1)
		return (ft_error(14));
	if (args->outfile == -1)
		return (ft_error(15));	
	return (0);
}
