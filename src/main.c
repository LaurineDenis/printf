/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:24:05 by ldenis            #+#    #+#             */
/*   Updated: 2021/03/02 17:55:54 by laurinedeni      ###   ########.fr       */
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
	dprintf(1, "--------------- TEST 1 ---------------\n");
	dprintf(1, "0*.*, 10, -10\n");
	ret1 = printf("v %0*.*%", 10, -10);
	printf("\n");
	ret2 = ft_printf("f %0*.*%", 10, -10);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	dprintf(1, "--------------- TEST 2 ---------------\n");
	dprintf(1, "10.*, 10\n");
	ret1 = printf("v %10.*%", 10);
	printf("\n");
	ret2 = ft_printf("f %10.*%", 10);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	printf("\n");
	dprintf(1, "--------------- TEST 3 ---------------\n");
	dprintf(1, "020.2\n");
	ret1 = printf("v %020.2%");
	printf("\n");
	ret2 = ft_printf("f %020.2%");
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	printf("\n");
	dprintf(1, "--------------- TEST 4 ---------------\n");
	dprintf(1, "*.*, -45, -45\n");
	ret1 = printf("v %*.*%", -45, -45);
	printf("\n");
	ret2 = ft_printf("f %*.*%", -45, -45);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	printf("\n");
	dprintf(1, "--------------- TEST 5 ---------------\n");
	dprintf(1, "*.*, 10, 3\n");
	ret1 = printf("v %*.*%", 10, 3);
	printf("\n");
	ret2 = ft_printf("f %*.*%", 10, 3);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	printf("\n");
	dprintf(1, "--------------- TEST 6 ---------------\n");
	dprintf(1, "*.*, 10, 1\n");
	ret1 = printf("v %*.*%", 10, 1);
	printf("\n");
	ret2 = ft_printf("f %*.*%", 10, 1);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	printf("\n");
	dprintf(1, "--------------- TEST 7 ---------------\n");
	dprintf(1, "10.*, -10\n");
	ret1 = printf("v %10.*%", -10);
	printf("\n");
	ret2 = ft_printf("f %10.*%", -10);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	printf("\n");
}
