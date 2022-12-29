/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/29 16:10:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_is_delimiter(char *str)
{
	if (ft_strcmp(str, "|"))
		return (str);
	if (ft_strcmp(str, "<"))
		return (str);
	if (ft_strcmp(str, ">"))
		return (str);
	if (ft_strcmp(str, "<<"))
		return (str);
	if (ft_strcmp(str, ">>"))
		return (str);
	return (NULL);
}

int	ft_get_instructions(t_args *args)
{
	char	*good_path;
	int i; 

	i = 0;
	while (args->command_list[i])
		i++;
	args->instructions = malloc(sizeof(char *) * (i + 1));
	if (!args->instructions)
		return (99);
	i = 0;
	while (args->command_list[i])
	{
		good_path = ft_get_path(args->envp, args->command_list[i]);
		if (good_path)
			args->instructions[i] = good_path;
		else
			args->instructions[i] = args->command_list[i];
		i++;
	}
	args->instructions[i] = NULL;
	return (0);
}

int	ft_execute_command(t_args *args)
{
	int i;

	i = 0;
	ft_get_instructions(args);

	while (args->instructions[i])
	{
	
		printf("%s\n", args->instructions[i]);
		free(args->instructions[i++]);
	}
	free(args->instructions);

	

	//while (args->command_list[i])
	//	printf("%s\n", args->command_list[i++]);
	(void)args;
	//TODO
	return (0);
}

int	ft_prompt_loop(t_args *args)
{
	char	*command;
	int		error_code;

	while (!args->exit_code)
	{
		command = readline(args->prompt);
		args->command_list = ft_split(command, ' ');
		error_code = ft_execute_command(args);
		if (error_code)
			return (error_code);
		if (args->command_list[0] && \
				!ft_strcmp(args->command_list[0], "exit"))
			args->exit_code = 1;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;
	int		error_code;

	args = malloc(sizeof(t_args));
	if (!args)
		return (ft_error(99));
	error_code = ft_struct_init(args);
	if (error_code)
		return (ft_error(error_code));
	args->envp = envp;
	error_code = ft_prompt_loop(args);
	if (error_code)
		return (ft_error(error_code));
	(void)argc;
	(void)argv;
	return (0);
}
