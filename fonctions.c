/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:16:22 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/04 18:27:55 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(va_list ap, print_list *lst)
{
	char	c;
	char	s[2];

	c = (char)va_arg(ap, int);
	s[0] = c;
	s[1] = '\0';
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	// dprintf(1, "print c = %s\n", lst->print);
}

void	print_s(va_list ap, print_list *lst)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		return ;
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	// printf("print s = %s\n", lst->print);
}

void	print_d_i(va_list ap, print_list *lst)
{
	int		i;
	char	*ret;

	i = va_arg(ap, int);
	ret = ft_itoa(i);
	if (i < 0 && lst->flag_0 == 1 && lst->flag_point == 0)
	{
		lst->verif = 1;
		ret = ft_substr(ret, 1, ft_strlen(ret));
	}
	if (!(lst->print = ft_strfjoin(lst->print, ret, 1)))
		return ;
	free(ret);
	// ft_putnbr_fd(i, 1);
	// printf("print d/i = %s\n", lst->print);
}

void	print_p(va_list ap, print_list *lst)
{
	char		*s;
	long long int			i;

	i = va_arg(ap, long long int);
	s = ft_itoa_hexa_l(i, "0123456789abcdef");
	if (!s || ft_strlen(s) == 0)
		s = "0\0";
	if (!(lst->print = ft_strfjoin(lst->print, "0x", 1)))
		return ;
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	// printf("print p = %s\n", lst->print);
}

void		print_u(va_list ap, print_list *lst)
{
	unsigned int		i;
	char				*ret;

	i = va_arg(ap, unsigned int);
	ret = ft_itoa_unsi(i);
	if (!(lst->print = ft_strfjoin(lst->print, ret, 1)))
		return ;
	// printf("print u = %s\n", lst->print);
}
