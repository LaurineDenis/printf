/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/16 16:33:56 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_c(char c)
{
	char	*convert;
	int		i;

	convert = "csdpuixX";
	i = 0;
	while (convert[i])
	{
		if (convert[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int		is_f(char c)
{
	char	*flag;
	int		i;

	flag = "-0.*";
	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	size_t		len;
	print_list	*lst;
	void		(*tab_fonction[121])(va_list, print_list *);

	i = 0;
	len = ft_strlen(str);
	init_tab(tab_fonction);
	lst = init_struct();

	va_start(ap, str);
	while (i < len)
	{
		if (str[i] == '%' && is_c(str[i + 1]) != 0)
		{
			(tab_fonction[str[i + 1]])(ap, &lst);
			i += 2;
		}
		// else if (str[i] == '%' && is_f(str[i + 1]) != 0)
		// {

		// }
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
	ft_printf("%s %c %d %p %i %u %x %X", s, c, i, &s, i, u, i, i);
}
