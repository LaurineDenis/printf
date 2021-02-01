/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/01 13:32:05 by ldenis           ###   ########lyon.fr   */
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
	print_list		*begin;
	char			*ret;
	size_t			len;

	lst = init_struct();
	begin = lst;
	ret = ft_calloc(1, 1);
	va_start(ap, str);
	ret = parse(ret, str, &lst, ap);
	len = ft_strlen(ret);
	len = aff_zero(lst, ret, len);
	va_end(ap);
	lst_free(&begin);
	free(ret);
	return (len);
}
