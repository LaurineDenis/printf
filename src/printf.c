/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/13 12:37:26 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	va_list			ap;
	print_list		*lst;
	char			*ret;
	size_t			len;
	static void		(*grid[121])(va_list, print_list *, char *) = {0};

	init_tab(grid);
	lst = init_struct();
	ret = ft_calloc(1, 1);
	va_start(ap, str);
	ret = parse(ret, str, &lst, ap);
	len = ft_strlen(ret);
	len = aff_zero(lst, ret, len);
	va_end(ap);
	return (len);
}
