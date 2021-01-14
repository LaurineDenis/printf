/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/14 12:55:00 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_main(void)
{
	char			c;
	char			*s;
	int				i;
	unsigned int	u;

	c = 'a';
	s = "str";
	i = -21;
	u = 25;
	printf("1 printf = \t|%0d|\n", i);
	ft_printf("1 ft_printf = \t|%0d|\n", i);
}

int		main(void)
{
	ft_main();
	while (1);
}