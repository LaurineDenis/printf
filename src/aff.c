/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:33 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/03 14:49:39 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		aff_printf(t_print *lst, int len, int aff, char *ret)
{
	char	*str;

	if (aff == 1)
	{
		back200(lst, ret);
		str = ft_substr(ret, lst->index_b + 1, len);
		write(1, ret, lst->index_b);
		write(1, "\0", 1);
		write(1, str, ft_strlen(str));
		free(str);
		return (len);
	}
	write(1, ret, len);
	return (len);
}

int		aff_zero(t_print *lst, char *ret, size_t len)
{
	int		aff;
	int		i;

	aff = 0;
	i = 0;
	while (lst)
	{
		i++;
		if (lst->backslash == 1)
		{
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
