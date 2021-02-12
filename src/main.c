/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/12 17:00:05 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	int				ret1;
	int				ret2;

	ret1 = 0;
	ret2 = 0;
	ret1 = printf("v %s", NULL);
	printf("\n");
	ret2 = ft_printf("f %s", NULL);
	dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
}
