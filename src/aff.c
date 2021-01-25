/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:33 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/25 16:28:02 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		aff_printf(print_list *lst, int len, int aff, char *ret)
{
	char	*str;

	if (aff == 1)
	{
		back200(lst, ret);
		str = ft_substr(ret, lst->index_b + 1, len);
		write(1, ret, lst->index_b);
		// dprintf(1, "ret = %s\n", ret);
		// dprintf(1, "index = %d\n", lst->index_b);
		// dprintf(1, "ret[i] = %c\n", ret[lst->index_b]);
		write(1, "\0", 1);
		write(1, str, ft_strlen(str));
		// dprintf(1, "str = %s\n", str);
		free(str);
		return (len);
	}
	// printf("len = %d\n", len);
	printf("ret = %s\n", ret);
	write(1, ret, len);
	// printf("ret = %s\n", ret);
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
