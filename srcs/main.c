/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/27 19:06:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_command(t_args *args)
{
	(void)args;
	//TODO
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	int	error_code;

	while (!args->exit_code)
	{
		args->command = readline(args->prompt);
		args->command_list = ft_split(args->command, ' ');
		error_code = ft_execute_command(args);
		if (error_code)
			return (error_code);
		if (args->command_list[0] && \
				!ft_strcmp(args->command_list[0], "exit"))
			args->exit_code = 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	*args;
	int		error_code;

	args = malloc(sizeof(t_args));
	if (!args)
		return (ft_error(99));
	error_code = ft_struct_init(args);
	if (error_code)
		return (ft_error(error_code));
	error_code = ft_prompt_loop(args);
	if (error_code)
		return (ft_error(error_code));
	(void)argc;
	(void)argv;
	return (0);
}
