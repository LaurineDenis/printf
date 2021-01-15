/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:25:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/15 13:45:27 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		verif_fill(print_list *lst, int i)
{
	if (lst->size_point <= 1)
		lst->flag_0 = 0;
	if (lst->convert == '%')
		lst->size_point = 1;
	if (lst->size < lst->size_point)
		lst->size = lst->size_point;
	if (i == 0 && lst->backslash == 1)
		i++;
	return (i);
}

void		back200(print_list *lst, char *ret)
{
	int		i;

	i = 0;
	while (ret[i] != '\200')
		i++;
	lst->index_b = i;
}

void		verif(print_list *lst)
{
	if (lst->flag_point == 0 && lst->convert == 'i')
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	if (lst->convert == 'd' && lst->flag_point == 0)
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	lst->print = ft_strfjoin("-\0", lst->print, 2);
}
