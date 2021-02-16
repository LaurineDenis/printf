/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/16 09:48:57 by ldenis           ###   ########lyon.fr   */
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
	ret1 = printf("v %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("\n");
	ret2 = ft_printf("f %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	// ret1 = printf("v %c", '\200');
	// printf("\n");
	// ret2 = ft_printf("f %c", '\200');
	// dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	// printf("\n");
}

// int		main()
// {
// 	ft_main();
// 	while (1)
// 	;
// }
