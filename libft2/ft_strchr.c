/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:41:24 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/09 18:48:30 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;
	size_t			len;

	i = 0;
	ch = c;
	len = 0;
	while (s[len])
		len++;
	while (i <= len)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
