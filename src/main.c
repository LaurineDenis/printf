/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:15:37 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/16 14:37:33 by ldenis           ###   ########lyon.fr   */
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
	ret1 = printf("v |%046d|", -120);
	printf("\n");
	ret2 = ft_printf("f |%046d|", -120);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	// ret1 = printf("v %c", '\200');
	// printf("\n");
	// ret2 = ft_printf("f %c", '\200');
	// dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
	// printf("\n");
}
