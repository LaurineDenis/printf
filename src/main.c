/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:18:46 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/13 12:37:15 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		main(void)
{
	char			c;
	char			*s;
	int				i;
	unsigned int	u;

	c = 'a';
	s = "str";
	i = -21;
	u = 25;
	printf("1 printf = \t|%s|\n", s);
	ft_printf("1 ft_printf = \t|%s|\n", s);
}
