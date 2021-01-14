/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:39:15 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/14 12:21:19 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	lst_free(print_list *lst)
{
	print_list  *sav;

	if (!lst)
		return ;
	while (lst->next)
	{
		sav = lst;
		free(lst->print);
		free(lst);
		lst = sav->next;
	}
	free(lst->print);
	free(lst);
}