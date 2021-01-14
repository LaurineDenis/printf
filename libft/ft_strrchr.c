/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:21:37 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/14 14:12:58 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen((char *)s);
	if (!(c))
		return ((char *)s + i);
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (NULL);
}
