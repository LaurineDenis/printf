/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:25:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/10 13:55:59 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		verif_fill(t_print *lst, int i)
{
	if (lst->convert == '%')
		lst->size_point = 1;
	if (lst->size < lst->size_point)
		lst->size = lst->size_point;
	if (i == 0 && lst->backslash == 1)
		i++;
	return (i);
}

void	back200(t_print *lst, char *ret)
{
	int		i;

	i = 0;
	while (ret[i] != '\200')
		i++;
	lst->index_b = i;
}

int		verif(t_print *lst, int i)
{
	int		j;

	j = 0;
	i = test(lst, i);
	if (lst->verif == 1)
		lst->print = ft_strfjoin("-\0", lst->print, 2);
	else
		i--;
	return (i);
}

int		test(t_print *lst, int i)
{
	if (lst->flag_0 == 1 && lst->flag_etoile == 1 && lst->size_point <= 1)
	{
		if (lst->flag_tiret == 0)
		{
			if (lst->convert == 'u' || lst->convert == 'x')
				lst->size_point = lst->size + 1;
			else if (lst->convert == 'X')
				lst->size_point = lst->size + 1;
			else if (lst->verif == 1)
				lst->size_point = lst->size;
			// else
			// 	return (i);
			while (i++ < lst->size_point)
				lst->print = ft_strfjoin("0\0", lst->print, 2);
			i--;
		}
	}
	return (i);
}
