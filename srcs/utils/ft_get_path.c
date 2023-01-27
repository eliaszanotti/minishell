/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:42:28 by elias             #+#    #+#             */
/*   Updated: 2023/01/27 13:50:05 by elias            ###   ########.fr       */
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

char	*ft_get_path(char *cmd)
{
	char	**paths;
	char	*good_path;
	int		i;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	paths = ft_split(getenv("PATH"), ':');
	if (!paths)
		return (NULL);
	i = 0;
	good_path = NULL;
	while (paths[i])
	{
		good_path = ft_pathjoin(paths[i++], cmd);
		if (access(good_path, F_OK) == 0)
			break;
		free(good_path);
	}
	ft_free_str(paths);
	return (good_path);
}
