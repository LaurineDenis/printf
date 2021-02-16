/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:50:43 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/02/16 10:20:32 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_print	*init_struct(void)
{
	t_print		*new;

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

t_print	*add_back_lst(t_print **first, t_print *last)
{
	t_print	*tmp;

	tmp = (*first);
	if ((*first) == NULL)
		tmp = last;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = last;
	}
	return (tmp->next);
}
