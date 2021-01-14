/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:59:27 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/14 14:31:33 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_fatoi(const char *str)
{
	int res;
	int sign;
	void	*save;

	res = 0;
	sign = 1;
	save = (void *)str;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
    free(save);
	return (res * sign);
}
