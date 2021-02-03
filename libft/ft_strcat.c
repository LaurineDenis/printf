/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:27:49 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/02 16:29:06 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[i])
		j++;
	k = i + j + 1;
	j = 0;
	while (i < k)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (i == k)
		dest[i] = '\0';
	return (dest);
}
