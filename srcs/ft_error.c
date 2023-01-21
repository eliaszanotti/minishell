/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/01/21 14:07:58 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code == 1)
		printf("Parse error (quote not closed)\n");
	if (error_code == 2)
		printf("Command not found\n");
	if (error_code == 3)
		printf("Can't open file\n");
	if (error_code == 4)
		printf("Failed to create fork\n");
	if (error_code == 5)
		printf("Failed to execute command\n");
	if (error_code == 6)
		printf("Failed to duplicate fd (dup2 error)\n");
	if (error_code == 7)
		printf("Failed to pipe fd\n");
	if (error_code == 99)
		printf("Malloc cannot be created\n");
	return (error_code);
}
