/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:17:03 by elias             #+#    #+#             */
/*   Updated: 2023/04/27 15:23:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_args *args)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	ft_printf_fd("%s\n", args->outfile, cwd);
	return (0);
}
