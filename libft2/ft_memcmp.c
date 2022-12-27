/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:51:51 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/11 16:07:59 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;
	size_t			i;

	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && copy_s1[i] == copy_s2[i])
		i++;
	return (copy_s1[i] - copy_s2[i]);
}
