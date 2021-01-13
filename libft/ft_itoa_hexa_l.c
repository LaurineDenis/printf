/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:47:52 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/14 16:34:39 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_hexa_l(unsigned long n, char *base)
{
	int					i;
	unsigned long		tmp;
	unsigned long		nb;
	char				*ret;

	tmp = n;
	i = 1;
	nb = n;
	while ((tmp = tmp / 16) > 0)
		i++;
	if (!(ret = (char *)ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	while (nb > 0)
	{
		ret[--i] = base[nb % 16];
		nb = nb / 16;
	}
	return (ret);
}
