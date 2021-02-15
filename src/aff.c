/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:33 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/15 16:45:44 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		aff_printf(t_print *lst, int len, int aff, char *ret, int i)
{
	char	**split;
	char	*str;
	int		j;

	j = 0;
	(void)lst;
	if (aff == 1)
	{
		if (i == 1)
		{
			back200(lst, ret);
			str = ft_substr(ret, lst->index_b + 1, len);
			write(1, ret, lst->index_b);
			write(1, "\0", 1);
			write(1, str, ft_strlen(str));
			free(str);
			return (len);
		}
		else
		{
			split = ft_split(ret, '\200');
			while (j < i)
			{
				write(1, split[j], ft_strlen(split[j]));
				write(1, "\0", 1);
				j++;
			}
			write(1, split[j], ft_strlen(split[j]));
			j = -1;
			while (++j <= i)
				dprintf(1, "split[%d] = %s\n", j, split[j]);
			free(split);
			return (len);
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
