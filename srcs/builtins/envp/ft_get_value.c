/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:37:32 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:24:38 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1][i] && cmd[1][i] != '=')
		i++;
	return (cmd[1] + i + 1);
}
