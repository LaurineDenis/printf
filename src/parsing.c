/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:15:02 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/25 15:41:16 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*parse(char *ret, const char *str, print_list **lst, va_list ap)
{
	print_list	*beg;
	print_list	*next;
	size_t		i;

	i = 0;
	next = NULL;
	beg = (*lst);
	while (str[i])
	{
		while (str[i] == '%')
		{
			i++;
			(*lst) = add_back_lst(lst, init_struct());
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

	ret = NULL;
	init_tab(tab_fonction);
	(*lst)->convert = str[i];
	(tab_fonction[(int)str[i]])(ap, *lst, (char *)str);
	fill_print(*lst);
	ret = ft_substr((*lst)->print, 0, ft_strlen((*lst)->print));
	// dprintf(1, "-----------NEW FLAG-----------\n");
	// dprintf(1, "convert = %c\n", (*lst)->convert);
	// dprintf(1, "adresse = %p\n", (*lst));
	// dprintf(1, "adresse next = %p\n", (*lst)->next);
	// dprintf(1, "flag_0 = %d\n", (*lst)->flag_0);
	// dprintf(1, "flag_point = %d\n", (*lst)->flag_point);
	// dprintf(1, "flag_etoile = %d\n", (*lst)->flag_etoile);
	// dprintf(1, "flag_tiret = %d\n", (*lst)->flag_tiret);
	// dprintf(1, "backslash = %d\n", (*lst)->backslash);
	// dprintf(1, "verif = %d\n", (*lst)->verif);
	// dprintf(1, "size = %d\n", (*lst)->size);
	// dprintf(1, "size_point = %d\n", (*lst)->size_point);
	// dprintf(1, "print = %s\n", (*lst)->print);
	return (ret);
}
