/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:32:36 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/03 14:49:39 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		init_tab(void (*grid[121])(va_list ap, t_print *lst, char *str))
{
	grid[37] = &print_per;
	grid[88] = &print_bigx;
	grid[99] = &print_c;
	grid[100] = &print_d_i;
	grid[105] = &print_d_i;
	grid[112] = &print_p;
	grid[115] = &print_s;
	grid[117] = &print_u;
	grid[120] = &print_x;
}
