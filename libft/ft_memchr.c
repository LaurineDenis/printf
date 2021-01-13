/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:19:55 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/04 10:39:34 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;
	size_t			j;

	tmp_s = (unsigned char *)s;
	i = -1;
	j = 0;
	while (j < n)
	{
		i++;
		if (tmp_s[i] == (unsigned char)c)
			return (tmp_s + i);
		j++;
	}
	return (0);
}
