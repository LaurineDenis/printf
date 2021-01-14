/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:33 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/14 12:23:18 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		aff_printf(print_list *lst, int len, int aff, char *ret)
{
	char	*str;

	if (aff == 1)
	{
		str = ft_substr(ret, lst->index_b, len - lst->index_b);
		write(1, ret, lst->index_b);
		write(1, "\0", 1);
		write(1, str, ft_strlen(str));
		free(str);
		return (len);
	}
	write(1, ret, len);
	return (len);
}

int		aff_zero(print_list *lst, char *ret, size_t len)
{
	int		aff;
	int		i;

	aff = 0;
	i = 0;
	while (lst && lst->next != NULL)
	{
		i++;
		if (lst->backslash == 1)
		{
			if (lst->flag_0 == 0 || lst->flag_etoile == 0)
				len = len + 1;
			else if (lst->flag_point == 0 || lst->flag_tiret == 0)
				len = len + 1;
			aff = 1;
			if (i > 1)
				lst->index_b -= 1;
			break ;
		}
		lst = lst->next;
	}
	len = aff_printf(lst, len, aff, ret);
	return (len);
}
