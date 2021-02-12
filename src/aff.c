/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:33 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/12 16:48:35 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		aff_printf(t_print *lst, int len, int aff, char *ret, int i)
{
	char	**str;
	int		j;

	j = 0;
	(void)lst;
	if (aff == 1)
	{
		while (j < i)
		{
			// back200(lst, ret);
			str = ft_split(ret, '\200');
			// str = ft_substr(ret, lst->index_b + 1, len);
			write(1, str[j], ft_strlen(*(str + j)));
			write(1, "\0", 1);
			// lst = lst->next;
			j++;
		}
		write(1, str[j], ft_strlen(str[j]));
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
