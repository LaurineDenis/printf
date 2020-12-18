/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:16:22 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/18 12:11:52 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(va_list ap, print_list *lst)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (!(lst->print = malloc(sizeof(char) * 2)))
		return ;
	lst->print[0] = c;
	lst->print[1] = '\0';
	// ft_putchar_fd(c, 1);
	// printf("print c = %s\n", lst->print);
}

void	print_s(va_list ap, print_list *lst)
{
	char	*s;

	s = va_arg(ap, char*);
	lst->print = ft_strdup(s);
	// ft_putstr_fd(s, 1);
	// printf("print s = %s\n", lst->print);
}

void	print_d_i(va_list ap, print_list *lst)
{
	int		i;
	char	*ret;

	i = va_arg(ap, int);
	ret = ft_itoa(i);
	lst->print = ft_strdup(ret);
	// ft_putnbr_fd(i, 1);
	// printf("print d/i = %s\n", lst->print);
}

void	print_p(va_list ap, print_list *lst)
{
	char		*s;
	long long int			i;

	i = va_arg(ap, long long int);
	s = ft_itoa_hexa_l(i, "0123456789abcdef");
	lst->print = ft_strdup(s);
	lst->print = ft_strfjoin("0x", lst->print, 2);
	// ft_putstr_fd(s, 1);
	// printf("print p = %s\n", lst->print);
}

void		print_u(va_list ap, print_list *lst)
{
	unsigned int		i;
	char				*ret;

	i = va_arg(ap, unsigned int);
	ret = ft_itoa_unsi(i);
	lst->print = ft_strdup(ret);
	// ft_putnbr_unsi(i, 1);
	// printf("print u = %s\n", lst->print);
}
