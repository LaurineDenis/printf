/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:39:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/25 10:55:55 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	lst_free(print_list **lst)
{
	print_list  *sav;

	sav = NULL;
	while (*lst)
	{
		sav = (*lst)->next;
		free((*lst)->print);
		free(*(lst));
		(*lst) = sav;
	}
	(*lst) = NULL;
}
