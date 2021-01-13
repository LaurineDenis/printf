/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:09:07 by ldenis            #+#    #+#             */
/*   Updated: 2020/11/28 17:11:28 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_counter_word(const char *str, char set)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	if (str[0] != set)
		counter++;
	while (str[i])
	{
		if (str[i] == set && str[i + 1] != set)
			counter++;
		i++;
	}
	return (counter);
}
