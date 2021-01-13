/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:21:21 by ldenis            #+#    #+#             */
/*   Updated: 2020/11/28 18:33:42 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		i2;
	size_t		mem_len;

	mem_len = len;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (haystack[0] == 0)
		return (0);
	if (len == 0)
		return (NULL);
	i = -1;
	while (haystack[++i] && len > 0)
	{
		i2 = 0;
		while (haystack[i + i2] == needle[i2] && i + i2 < mem_len)
			if (!needle[++i2])
				return ((char *)haystack + i);
		len--;
	}
	return (0);
}
