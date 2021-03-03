/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:27 by ldenis            #+#    #+#             */
/*   Updated: 2021/03/03 09:48:26 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_per(va_list ap, t_print *lst, char *str)
{
	char	s[2];
	int		i;

	s[0] = '%';
	s[1] = '\0';
	i = 0;
	(void)ap;
	if (lst->size == 0 && lst->size_point > 0 && lst->flag_point == 1)
		lst->size_point = 0;
	if (lst->size_point >= 1)
	{
		while (str[i] != '%' && str[i])
			i++;
		if (str[i + 1] != '0')
			lst->flag_0 = 0;
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	t_print			*lst;
	t_print			*begin;
	char			*ret;
	size_t			len;

	lst = init_struct();
	begin = lst;
	ret = NULL;
	va_start(ap, str);
	ret = parse(ret, (char *)str, &lst, ap);
	len = ft_strlen(ret);
	len = aff_zero(lst, ret, len);
	va_end(ap);
	lst_free(&begin);
	free(ret);
	return (len);
}
