/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:27:08 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/01 16:14:00 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	ft_memcpy((void *)str, (const void *)s1, ft_strlen(s1));
	ft_strlcat((char *)str, (char *)s2, len + 1);
	return (str);
}
