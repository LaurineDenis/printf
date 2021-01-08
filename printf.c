/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/08 12:37:02 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_per(va_list ap, print_list *lst)
{
	char	s[2];

	s[0] = '%';
	s[1] = '\0';
	(void)ap;
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}

int		is_c(char c)
{
	char	*convert;
	int		i;

	convert = "csdpuixX%";
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

	flag = "-.*0123456789";
	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (flag[i]);
		i++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	print_list	*lst;
	char		*ret;
	void		(*tab_fonction[121])(va_list, print_list *);

	init_tab(tab_fonction);
	lst = NULL;
	ret = ft_calloc(1, 1);
	va_start(ap, str);
	ret = parse(ret, str, lst, ap);
	write(1, ret, ft_strlen(ret));
	va_end(ap);
	return (ft_strlen(ret));
}

// int		main(void)
// {
// 	char		c;
// 	// char		s[4] = "str";
// 	int			i;
// 	unsigned int u;

// 	c = 'a';
// 	i = -2;
// 	u = 25;
// 	printf("|%c%c|\n", 'c', 0);
// 	ft_printf("|%c%c|\n", 'c', 0);
// }
