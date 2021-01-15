/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/15 14:22:21 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	char			c;
	char			*s;
	int				i;
	unsigned int	u;
	int				ret1;
	int				ret2;

	c = 'a';
	s = "str";
	i = -21;
	u = 25;
	ret1 = printf(" %-.2d \n", 0);
	ret2 = ft_printf(" %-.2d \n", 0);
	dprintf(1, "ret 1 = %d\nret 2 = %d\n", ret1, ret2);
}

// int		main(void)
// {
// 	ft_main();
// 	while (1);
// }