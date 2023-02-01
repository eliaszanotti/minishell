/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/01 12:20:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_dir(t_args *args, char *cwd)
{
	char	*dir;
	char	*var;
	int		size;

	size = ft_strlen(cwd);
	while (cwd[size] != '/')
		size--;
	var = ft_getenv(args, "HOME");
	if (!var)
	{
		free(var);
		return (ft_strdup(" ⚡\001\e[46;90m\ue0b0\002 ?"));
	}
	if (!ft_strcmp(cwd, var))
		dir = ft_strjoin(" ⚡\001\e[46;90m\ue0b0\002 ", "~");
	else
		dir = ft_strjoin(" ⚡\001\e[46;90m\ue0b0\002 ", cwd + size + 1);
	free(var);
	return (dir);
}

static char	*ft_get_logname(t_args *args)
{
	char	*logname;

	logname = ft_getenv(args, "LOGNAME");
	if (!logname)
		return (ft_strdup("John DOE"));
	return (logname);
}

char	*ft_get_prompt(t_args *args, char *cwd)
{
	char	*logname;
	char	*start;
	char	*tmp;

	if (cwd)
	{
		cwd = ft_get_dir(args, cwd);
		logname = ft_get_logname(args);
		start = ft_strjoin("\001\e[100;36m ", logname);
		free(logname);
		tmp = ft_strjoin(start, cwd);
		free(start);
		free(cwd);
		cwd = ft_strjoin(tmp, " \001\e[36;49m\ue0b0\e[0m\002 ");
		free(tmp);
		return (cwd);
	}
	return (NULL);
}
