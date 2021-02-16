/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:17:19 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/16 10:23:55 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	int		size;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	size = (ft_strlen(s) > len) ? len : (ft_strlen(s) - start);
	if (!(dst = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < len && s[start])
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
