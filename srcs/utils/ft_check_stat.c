/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:46:50 by elias             #+#    #+#             */
/*   Updated: 2023/06/21 19:43:26 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_stat(char *path)
{
	struct stat	file_stat;
	int			i;

	i = -1;
	while (path[++i])
		;
	if (path[i - 1] == '/' || path[0] == '/')
	{
		if (stat(path, &file_stat) != 0)
			return (ft_error(1265, path), 1);
		if (S_ISREG(file_stat.st_mode))
			return (ft_error(1265, path), 1);
		else
			return (ft_error(1264, path), 1);
	}
	else if (path[0] == '.' && path[1] == '/')
	{
		if (stat(path, &file_stat) != 0)
			return (ft_error(1270, path), 1);
		if (S_ISREG(file_stat.st_mode))
			return (1);
	}
	ft_error(1270, path);
	return (1);
}
