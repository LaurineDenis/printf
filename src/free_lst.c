/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:39:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/14 15:17:29 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	lst_free(print_list **lst)
{
	print_list  *sav;
	print_list	*beg;

	sav = NULL;
	beg = (*lst);
	while (*lst)
	{
		sav = (*lst)->next;
		free((*lst)->print);
		free(*lst);
		(*lst) = sav;
	}
	free(*lst);
	(*lst) = NULL;
	beg = NULL;
}