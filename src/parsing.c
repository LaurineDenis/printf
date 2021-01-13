/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:15:02 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/13 12:37:18 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*parse(char *ret, const char *str, print_list **lst, va_list ap)
{
	print_list	*beg;
	size_t		i;

	i = 0;
	beg = (*lst);
	while (str[i])
	{
		while (str[i] == '%')
		{
			i++;
			add_back_lst(lst, init_struct());
			while (is_c(str[i]) != 0 || is_f(str[i]) != 0)
			{
				if (is_c(str[i]) != 0)
				{
					ret = ft_strfjoin(ret, parsing(i++, str, lst, ap), 3);
					break ;
				}
				i = add_flag(*lst, str, i, ap);
			}
		}
		ret = ft_strfjoin(ret, ft_substr(str, i++, 1), 3);
	}
	(*lst) = ((*lst)->next != NULL) ? beg : beg->next;
	return (ret);
}

char		*parsing(int i, const char *str, print_list **lst, va_list ap)
{
	void		(*tab_fonction[121])(va_list, print_list *, char *);
	char		*ret;

	ret = ft_calloc(1, 1);
	init_tab(tab_fonction);
	(*lst)->convert = str[i];
	(tab_fonction[(int)str[i]])(ap, *lst, (char *)str);
	fill_print(*lst);
	ret = ft_substr((*lst)->print, 0, ft_strlen((*lst)->print));
	return (ret);
}
