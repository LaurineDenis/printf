/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/25 16:29:04 by ldenis           ###   ########lyon.fr   */
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
	i = 21;
	u = 25;
	ret1 = 0;
	ret2 = 0;
	ret1 = printf("true = %c", 0);
	printf("\n\n\n");
	ret2 = ft_printf("%c", 0);
	// dprintf(1, "\nret 1 = %d\nret 2 = %d\n", ret1, ret2);
}

// int		main(void)
// {
// 	ft_main();
// 	while (1);
// }
