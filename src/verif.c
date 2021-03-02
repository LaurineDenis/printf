/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:25:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/03/02 16:57:21 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		verif_fill(t_print *lst, int i)
{
	if (lst->convert == '%')
		return (verif_percent(lst, i));
	if (lst->size_point == 0 && lst->flag_point == 1)
		lst->flag_0 = 0;
	if (lst->size_point == 1 && lst->size > 1)
		lst->flag_0 = 0;
	if (lst->size <= 0)
		lst->size = lst->size * -1;
	if (lst->size == 1 && ft_strlen(lst->print) == 0)
		lst->flag_0 = 0;
	if (lst->size < lst->size_point)
	{
		lst->size = lst->size_point;
		lst->flag_0 = 1;
	}
	if (lst->flag_tiret == 1 && lst->size_point > 0)
		lst->flag_0 = 1;
	if (lst->flag_etoile == 0 && lst->flag_tiret == 0)
		if (lst->size_point > 0 && lst->flag_point == 1)
			lst->flag_0 = 1;
	if (lst->size_point > 1 && lst->second_wildcard == 0)
		lst->flag_0 = 1;
	if (i == 0 && lst->backslash == 1)
		i++;
	return (i);
}

int		verif_percent(t_print *lst, int i)
{
	// // (void)lst;
	// dprintf(1, "lst->size = %d\n", lst->size);
	// dprintf(1, "lst->size_point = %d\n", lst->size_point);
	if (lst->flag_tiret == 1 && lst->size_point > 0)
		lst->size_point = 0;
	if (lst->size < 0)
		lst->size = lst->size * -1;
	if (lst->flag_point == 1 && lst->second_wildcard == 1)
		lst->flag_0 = 0;
	if (lst->size_point < 0)
		lst->flag_0 = 1;
	lst->size_point = 0;
	return (i);
}

int		back200(t_print *lst, char *ret)
{
	int		i;

	i = 0;
	while (ret[i] != '\200')
		i++;
	lst->index_b = i;
	return (i);
}

int		verif(t_print *lst, int i)
{
	int		j;

	j = 0;
	if (lst->convert == '%')
	{
		if (lst->verif == 1)
			return (i);
		i--;
		return (i);
	}
	if (lst->size_point > 0 && lst->size > 0)
		lst->flag_0 = 0;
	if (lst->verif == 1 && lst->flag_0 == 0)
	{
		lst->print = ft_strfjoin("-\0", lst->print, 2);
		lst->verif = 0;
	}
	else if (lst->verif == 1)
		return (i);
	else
		i--;
	return (i);
}
