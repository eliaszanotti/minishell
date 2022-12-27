/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:45:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/14 10:49:05 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*copy_src;
	char		*copy_dest;

	if (!dest && !src)
		return (0);
	i = -1;
	copy_src = src;
	copy_dest = dest;
	while (++i < n)
		copy_dest[i] = copy_src[i];
	return (dest);
}
