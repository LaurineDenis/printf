/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:39:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/03 14:49:39 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	lst_free(t_print **lst)
{
	t_print	*sav;

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
