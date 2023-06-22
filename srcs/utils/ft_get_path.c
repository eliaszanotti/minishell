/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:42:28 by elias             #+#    #+#             */
/*   Updated: 2023/06/22 09:46:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_pathjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (*s1)
		str[i++] = *s1++;
	str[i++] = '/';
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_get_path(t_args *args, char *cmd)
{
	char	**paths;
	char	*good_path;
	int		i;

	if (!*cmd)
		return (NULL);
	if (cmd[ft_strlen(cmd) - 1] == '/')
		return (ft_strdup(cmd));
	if (access(cmd, F_OK) == 0 && \
		((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/'))
		return (ft_strdup(cmd));
	good_path = ft_getenv(args, "PATH");
	paths = ft_split(good_path, ':');
	if (!paths)
		return (NULL);
	free(good_path);
	i = 0;
	while (paths[i])
	{
		good_path = ft_pathjoin(paths[i++], cmd);
		if (access(good_path, X_OK) == 0)
			return (ft_free_str(paths), good_path);
		free(good_path);
	}
	return (ft_free_str(paths), NULL);
}
