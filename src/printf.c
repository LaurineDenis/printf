/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/14 12:08:13 by laurinedeni      ###   ########.fr       */
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
	lst_free(lst);
	free(ret);
	return (len);
}
