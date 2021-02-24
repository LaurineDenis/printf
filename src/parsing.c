/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:15:02 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/24 10:34:12 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*parse(char *ret, char *str, t_print **lst, va_list ap)
{
	t_print		*beg;
	t_print		*next;
	size_t		i;
	size_t		len;

	i = 0;
	next = NULL;
	beg = (*lst);
	ret = ft_calloc(1, 1);
	len = ft_strlen(str);
	while (str[i])
	{
		while (str[i] == '%' && i < len)
		{
			i++;
			(*lst) = add_back_lst(lst, init_struct());
			while (is_f(str[i]) != 0)
				i = add_flag(*lst, str, i, ap);
			if (is_c(str[i]) != 0)
				ret = ft_strfjoin(ret, parsing(i++, str, lst, ap), 3);
		}
		ret = ft_strfjoin(ret, ft_substr(str, i++, 1), 3);
	}
	(*lst) = ((*lst)->next != NULL) ? beg : beg->next;
	return (ret);
}

char		*parsing(int i, const char *str, t_print **lst, va_list ap)
{
	void		(*tab_fonction[121])(va_list, t_print *, char *);
	char		*ret;
	int			len;

	ret = NULL;
	init_tab(tab_fonction);
	(*lst)->convert = str[i];
	(tab_fonction[(int)str[i]])(ap, *lst, (char *)str);
	len = ft_strlen((*lst)->print);
	fill_print(*lst, len);
	ret = ft_substr((*lst)->print, 0, ft_strlen((*lst)->print));
	return (ret);
}
