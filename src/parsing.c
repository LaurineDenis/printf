/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:15:02 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/12 15:15:57 by laurinedeni      ###   ########.fr       */
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

	ret = NULL;
	init_tab(tab_fonction);
	(*lst)->convert = str[i];
	(tab_fonction[(int)str[i]])(ap, *lst, (char *)str);
	fill_print(*lst);
	ret = ft_substr((*lst)->print, 0, ft_strlen((*lst)->print));
	// dprintf(1, "-----------NEW FLAG-----------\n");
	// dprintf(1, "convert = %c\n", (*lst)->convert);
	// dprintf(1, "adresse = %p\n", (*lst));
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
