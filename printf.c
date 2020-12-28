/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/28 14:32:42 by ldenis           ###   ########lyon.fr   */
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
	size_t		i;
	size_t		len;
	print_list	*lst;
	print_list	*beg;
	char		*ret;
	void		(*tab_fonction[121])(va_list, print_list *);

	i = 0;
	len = ft_strlen(str);
	init_tab(tab_fonction);
	lst = NULL;
	beg = lst;
	ret = ft_calloc(1, 1);
	va_start(ap, str);
	while (i < len)
	{
		if (str[i] == '%')
		{
			i++;
			while (is_c(str[i]) != 0 || is_f(str[i]) != 0)
			{
				// dprintf(1, "start = %zu\n", i);
				// lst = init_struct();
				add_back_lst(&lst, init_struct());
				if (is_c(str[i]) != 0)
				{
					lst->convert = str[i];
					(tab_fonction[(int)str[i]])(ap, lst);
					size(lst);
					ret = ft_strfjoin(ret, lst->print, 1);
				}
				else
					i = add_flag(lst, str[i], str, i);
				i++;
			}
			printf("----------new_arg----------\n");
			printf("convert = %c\n", lst->convert);
			printf("flag_0 = %d\n", lst->flag_0);
			printf("flag_point = %d\n", lst->flag_point);
			printf("flag_etoile = %d\n", lst->flag_etoile);
			printf("flag_tiret = %d\n", lst->flag_tiret);
			printf("taille = %d\n", lst->taille);
			printf("print = %s\n", lst->print);
			lst = beg;
		}
		ret = ft_strfjoin(ret, ft_substr(str, i, 1), 3);
		i++;
	}
	printf("ret = %s\n", ret);
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
	ft_printf("%-10s\n%-c %-d %-p %-i %-u %-x %-X", s, c, i, &s, i, u, i, i);
}
