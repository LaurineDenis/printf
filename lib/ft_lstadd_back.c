/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:57:44 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/01 09:47:15 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*last;

	last = (*alst);
	if (!(*alst))
		(*alst) = new;
	else
	{
		(*alst) = ft_lstlast(*alst);
		(*alst)->next = new;
		(*alst) = last;
	}
}
