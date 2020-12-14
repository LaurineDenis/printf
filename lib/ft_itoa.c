/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 06:03:27 by ldenis            #+#    #+#             */
/*   Updated: 2020/11/28 13:08:15 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int					i;
	unsigned int		tmp;
	unsigned int		nb;
	char				*ret;

	tmp = n < 0 ? -n : n;
	i = n < 0 ? 2 : 1;
	nb = (n < 0) ? -n : n;
	while ((tmp = tmp / 10) > 0)
		i++;
	if (!(ret = (char *)ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	ret[--i] = ((nb % 10) + '0');
	while ((nb = nb / 10) > 0)
		ret[--i] = ((nb % 10) + '0');
	if (i != 0)
		ret[0] = '-';
	return (ret);
}
