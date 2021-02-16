/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:33 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/16 10:17:12 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		aff_printf(t_print *lst, int len, int aff, char *ret, int i)
{
	char	*str;
	int		j;
	int		index;

	j = 0;
	index = 0;
	(void)lst;
	(void)str;
	if (aff == 1)
	{
		while (j < i && lst)
		{
			while (ret[index] != '\200' && index < len)
				index++;
			ret[index] = '\0';
			j++;
		}
	}
	write(1, ret, len);
	return (len);
}

int		aff_zero(t_print *lst, char *ret, size_t len)
{
	int		aff;
	int		i;
	int		nb;
	t_print *first;

	aff = 0;
	i = 0;
	nb = 0;
	first = lst;
	while (lst != NULL)
	{
		i++;
		if (lst->backslash == 1)
		{
			aff = 1;
			nb++;
		}
		lst = lst->next;
	}
	lst = first;
	len = aff_printf(lst, len, aff, ret, nb);
	return (len);
}
