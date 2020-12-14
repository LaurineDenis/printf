/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:56:39 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/14 16:42:26 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_putchar_fd(c, 1);
	// printf("%c", c);
}

void	print_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_putstr_fd(s, 1);
	// printf("s = %s\n", s);
}

void	print_d(va_list ap)
{
	int		i;

	i = va_arg(ap, int);
	ft_putnbr_fd(i, 1);
	// printf("%d", i);
}

void	print_p(va_list ap)
{
	char		*s;
	long long int			i;

	i = va_arg(ap, long long int);
	// printf("%p\n", i);
	s = ft_itoa_hexa_l(i, "0123456789abcdef");
	write(1, "0x", 2);
	ft_putstr_fd(s, 1);
}

void	print_u(va_list ap)
{
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	ft_putnbr_unsi(i, 1);
	// printf("%d", i);
}

void	print_xX(va_list ap, char x)
{
	char		*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	if (x == 'x')
		s = ft_itoa_hexa_unsi(i, "0123456789abcdef");
	else if (x == 'X')
		s = ft_itoa_hexa_unsi(i, "0123456789ABCDEF");
	ft_putstr_fd(s, 1);
	// printf("%d", i);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	va_start(ap, str);
	while (i < len)
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			print_c(ap);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			print_s(ap);
			i += 2;
		}
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			print_d(ap);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'p')
		{
			print_p(ap);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == 'u')
		{
			print_u(ap);
			i += 2;
		}
		else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		{
			print_xX(ap, str[i + 1]);
			i += 2;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}

int		main(void)
{
	char		c;
	char		s[4] = "str";
	int			i;
	unsigned int u;

	c = 'a';
	i = 45;
	u = 25;
	ft_printf("%s %c %d %p %i\n%u\n%x\n%X", s, c, i, &s, i, u, i, i);
}
