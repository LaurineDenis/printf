/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/12 17:15:00 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_per(va_list ap, print_list *lst, char *str)
{
	char	s[2];

	s[0] = '%';
	s[1] = '\0';
	(void)str;
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
	size_t		len;
	void		(*tab_fonction[121])(va_list, print_list *, char *);

	init_tab(tab_fonction);
	lst = init_struct();
	ret = ft_calloc(1, 1);
	va_start(ap, str);
	ret = parse(ret, str, &lst, ap);
	len = ft_strlen(ret);
	len = aff_zero(lst, ret, len);
	va_end(ap);
	return (len);
}

int		aff_zero(print_list *lst, char *ret, size_t len)
{
	char	*str;
	int		aff;
	int		i;

	aff = 0;
	i = 0;
	// dprintf(1, "index = %d\n", lst->index_b);
	while (lst && lst->next != NULL)
	{
		i++;
		if (lst->backslash == 1)
		{
			if (lst->flag_0 == 0 || lst->flag_etoile == 0 || lst->flag_point == 0 || lst->flag_tiret == 0)
				len = len + 1;
			aff = 1;
			if (i > 1)
				lst->index_b -= 1;
			break ;
		}
		lst = lst->next;
	}
	if (aff == 1)
	{
		str = ft_substr(ret, lst->index_b, len - lst->index_b);
		write(1, ret, lst->index_b);
		write(1, "\0", 1);
		write(1, str, ft_strlen(str));
		return (len);
	}
	write(1, ret, len);
	return (len);
}

// int		main(void)
// {
// 	char		c;
// 	// char		s[4] = "str";
// 	int			i;
// 	unsigned int u;

// 	c = 'a';
// 	i = -21;
// 	u = 25;
// 	printf("1 printf = \t|%54.0s|\n", NULL);
// 	ft_printf("1 ft_printf = \t|%54.0s|\n", NULL);
// 	// printf("2 printf = \t|%54c|\n", 0);
// 	// ft_printf("2 ft_printf = \t|%54c|\n", 0);
// 	// printf("3 printf = \t|%54c|\n", 'c');
// 	// ft_printf("3 ft_printf = \t|%54c|\n", 'c');
// }
