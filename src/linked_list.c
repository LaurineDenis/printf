/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:50:43 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/14 12:10:49 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

print_list	*init_struct(void)
{
	print_list		*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->convert = 0;
	new->flag_0 = 0;
	new->flag_tiret = 0;
	new->flag_point = 0;
	new->flag_etoile = 0;
	new->size = 0;
	new->size_point = 0;
	new->verif = 0;
	new->backslash = 0;
	new->index_b = 0;
	new->next = NULL;
	new->print = ft_calloc(1, 1);
	return (new);
}

void		add_back_lst(print_list **first, print_list *new)
{
	if ((*first) == NULL)
		(*first) = new;
	else
	{
		while ((*first)->next != NULL)
			(*first) = (*first)->next;
		(*first)->next = new;
	}
}
