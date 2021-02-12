/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/10 14:12:35 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	int				ret1;
	int				ret2;

	ret1 = 0;
	ret2 = 0;
	ret1 = printf("v |%*.*d| \n", 4, 1, -12);
	printf("\n");
	ret2 = ft_printf("f |%*.*d| \n", 4, 1, -12);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
}
