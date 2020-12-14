/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:19:47 by ldenis            #+#    #+#             */
/*   Updated: 2020/11/28 17:19:49 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp_dst;
	unsigned char *temp_src;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n-- > 0)
	{
		*temp_dst = *temp_src;
		if (*temp_src == (unsigned char)c)
			return (temp_dst + 1);
		temp_dst++;
		temp_src++;
	}
	return (NULL);
}
