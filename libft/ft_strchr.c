/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:20:31 by ldenis            #+#    #+#             */
/*   Updated: 2020/11/28 17:20:33 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp_s;
	size_t	i;

	i = 0;
	temp_s = (char *)s;
	if (!c)
		return (temp_s + ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (temp_s[i] == c)
			return (temp_s + i);
		i++;
	}
	return (0);
}
