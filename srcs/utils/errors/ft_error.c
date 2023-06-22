/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/06/22 09:55:08 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_error_1(int error_code)
{
	g_last_errno = 1;
	if (error_code == 10)
		ft_print_error("Can't open file\n");
	else if (error_code == 11)
		ft_print_error("Can't create file\n");
	else if (error_code == 12)
		ft_print_error("No such file or directory\n");
	else if (error_code == 13)
		ft_print_error("exit: too many arguments\n");
	else if (error_code == 14)
		ft_print_error("export : not a valid identifier\n");
	else if (error_code == 15)
		ft_print_error("cd: too many arguments\n");
	return (1);
}

static int	ft_error_2(int error_code)
{
	g_last_errno = 2;
	if (error_code == 20)
		ft_print_error("Parse error (quote not closed)\n");
	else if (error_code == 21)
		ft_print_error("Parse error on pipe\n");
	else if (error_code == 22)
		ft_print_error("Syntax error on redirect\n");
	else if (error_code == 23)
		ft_print_error("Parse error at end of command\n");
	else if (error_code == 24)
		ft_print_error("exit: numeric argument required\n");
	else if (error_code == 25)
		ft_print_error("export: invalid option\n");
	return (1);
}

static int	ft_error_126(int error_code)
{
	g_last_errno = 126;
	if (error_code == 1260)
		ft_print_error("Failed to create fork\n");
	else if (error_code == 1261)
		ft_print_error("Failed to pipe fd\n");
	else if (error_code == 1262)
		ft_print_error("Failed to execute command\n");
	else if (error_code == 1263)
		ft_print_error("Failed to duplicate fd (dup2 error)\n");
	return (1);
}

static int	ft_error_command(int error_code, char *command)
{
	char	*new_str;
	char	*tmp;

	new_str = NULL;
	tmp = ft_strjoin("\e[1;31m[ERROR]\e[0m ", command);
	if (!tmp)
		return (1);
	if (error_code == 1270)
		new_str = ft_strjoin(tmp, ": Command not found\n");
	else if (error_code == 1264)
		new_str = ft_strjoin(tmp, ": Is a directory\n");
	else if (error_code == 1265)
		new_str = ft_strjoin(tmp, ": Not a directory\n");
	if (!new_str)
		return (1);
	write(STDERR_FILENO, new_str, ft_strlen(new_str));
	free(new_str);
	free(tmp);
	return (error_code / 10);
}

int	ft_error(int error_code, char *command)
{
	if (error_code && command)
		return (ft_error_command(error_code, command));
	if (error_code / 10 == 1)
		return (ft_error_1(error_code));
	if (error_code / 10 == 2)
		return (ft_error_2(error_code));
	if (error_code / 10 == 126)
		return (ft_error_126(error_code));
	else if (error_code == 99)
	{
		ft_print_error("Malloc cannot be created\n");
		return (99);
	}
	else
		ft_print_error("Undefined\n");
	return (1);
}
