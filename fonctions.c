/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:16:22 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/16 14:16:04 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(va_list ap, print_list *lst)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_putchar_fd(c, 1);
	// printf("%c", c);
}

void	print_s(va_list ap, print_list *lst)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_putstr_fd(s, 1);
	// printf("s = %s\n", s);
}

void	print_d(va_list ap, print_list *lst)
{
	int		i;

	i = va_arg(ap, int);
	ft_putnbr_fd(i, 1);
	// printf("%d", i);
}

void	print_i(va_list ap, print_list *lst)
{
	int		i;

	i = va_arg(ap, int);
	ft_putnbr_fd(i, 1);
	// printf("%d", i);
}

void	print_p(va_list ap, print_list *lst)
{
	char		*s;
	long long int			i;

	i = va_arg(ap, long long int);
	// printf("%p\n", i);
	s = ft_itoa_hexa_l(i, "0123456789abcdef");
	write(1, "0x", 2);
	ft_putstr_fd(s, 1);
}
