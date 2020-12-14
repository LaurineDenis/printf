/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:43:29 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/01 15:49:50 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int				ft_toupper(int c)
{
	if (ft_islower(c) == 1)
		return (c - 32);
	return (c);
}
