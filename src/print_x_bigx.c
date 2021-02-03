/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_bigx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:52:35 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/03 14:49:39 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		print_x(va_list ap, t_print *lst, char *str)
{
	char				*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	(void)str;
	s = ft_itoa_hexa_unsi(i, "0123456789abcdef");
	if (i == 0)
	{
		free(s);
		s = "0\0";
		if (lst->size_point == 0)
		{
			if (lst->flag_point == 1)
			{
				return ;
			}
		}
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	if (i != 0)
		free(s);
}

void		print_bigx(va_list ap, t_print *lst, char *str)
{
	char				*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	(void)str;
	s = ft_itoa_hexa_unsi(i, "0123456789ABCDEF");
	if (i == 0)
	{
		free(s);
		s = "0\0";
		if (lst->size_point == 0)
		{
			if (lst->flag_point == 1)
			{
				return ;
			}
		}
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	if (i != 0)
		free(s);
}
