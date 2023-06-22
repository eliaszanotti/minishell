/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:12:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/22 11:04:16 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_and_free(
	t_args *args, int error_code, char *path, char **command)
{	
	ft_free_stack(args->stack);
	ft_free_envp(args);
	free(args->close_tab);
	free(args->pid_tab);
	ft_free_instruction(args->command_list);
	ft_error(error_code, path);
	ft_free_str(command);
	exit(error_code / 10);
}
