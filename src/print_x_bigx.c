/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_bigx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:52:35 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/13 12:37:23 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		print_x(va_list ap, print_list *lst, char *str)
{
	char				*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	(void)str;
	s = ft_itoa_hexa_unsi(i, "0123456789abcdef");
	if (i == 0)
		s = "0\0";
	if (i == 0 && lst->size == 0)
	{
		if (lst->size_point == 0 && lst->flag_point == 1)
			return ;
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}

void		print_bigx(va_list ap, print_list *lst, char *str)
{
	char				*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	(void)str;
	s = ft_itoa_hexa_unsi(i, "0123456789ABCDEF");
	if (i == 0)
		s = "0\0";
	if (i == 0 && lst->size == 0)
	{
		if (lst->size_point == 0 && lst->flag_point == 1)
			return ;
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}
