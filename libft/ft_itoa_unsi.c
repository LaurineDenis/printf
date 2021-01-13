/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:14:43 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/18 11:15:53 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsi(unsigned int n)
{
	int					i;
	unsigned int		tmp;
	unsigned int		nb;
	char				*ret;

	tmp = n;
	i = 1;
	nb = tmp;
	while ((tmp = tmp / 10) > 0)
		i++;
	if (!(ret = (char *)ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	ret[--i] = ((nb % 10) + '0');
	while ((nb = nb / 10) > 0)
		ret[--i] = ((nb % 10) + '0');
	return (ret);
}
