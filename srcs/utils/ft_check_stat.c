/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:46:50 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 14:59:08 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_stat(char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) == 0 && S_ISREG(file_stat.st_mode))
		return (0);
	return (1);
}
