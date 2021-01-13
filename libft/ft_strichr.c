/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:14:09 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/18 12:14:23 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichr(const char *s, int c)
{
	char	*temp_s;
	int		i;

	i = 0;
	temp_s = (char *)s;
	if (!c)
		return (ft_strlen(s));
	while ((size_t)i < ft_strlen(s))
	{
		if (temp_s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
