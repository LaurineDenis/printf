/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:15:37 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/17 11:24:48 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int		main(void)
{
	int				ret1;
	int				ret2;
	ret1 = 0;
	ret2 = 0;
	ret1 = printf("v %0*.0d", 64, 184467440);
	printf("\n");
	ret2 = ft_printf("f %0*.0d", 64, 184467440);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	// ret1 = printf("v %c", '\200');
	// printf("\n");
	// ret2 = ft_printf("f %c", '\200');
	// dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	// printf("\n");
}
