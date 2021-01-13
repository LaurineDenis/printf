/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:56:37 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/13 12:37:08 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		init_tab(void (*grid[121])(va_list ap, print_list *lst, char *str))
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
