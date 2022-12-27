/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/27 18:42:34 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_prompt_loop(t_args *args)
{
	while (!args->exit_code)
	{
		args->command = readline(args->prompt);
		args->command_list = ft_split(args->command, ' ');
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

	ft_prompt_loop(args);

	(void)argc;
	(void)argv;
	return (0);
}
