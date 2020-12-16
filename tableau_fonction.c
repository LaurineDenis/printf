/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau_fonction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:34:32 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/16 15:01:49 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		init_tab(void (**tab_fonction)(va_list, print_list *))
{
	tab_fonction[88] = &print_X;
	tab_fonction[99] = &print_c;
	tab_fonction[100] = &print_d;
	tab_fonction[105] = &print_i;
	tab_fonction[112] = &print_p;
	tab_fonction[115] = &print_s;
	tab_fonction[117] = &print_u;
	tab_fonction[120] = &print_x;
}

print_list	*init_struct(void)
{
	print_list		*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->convert = 0;
	new->flag_0 = 0;
	new->flag_tiret = 0;
	new->flag_point = 0;
	new->flag_point = 0;
	new->taille = 0;
	new->next = NULL;
	new->print = NULL;
	return (new);
}

void		*add_back_lst(print_list **first, print_list *new)
{
	print_list		*save;

	save = (*first);
	if (!(*first))
		(*first) = new;
	else
	{
		while ((*first)->next)
			first = (*first)->next;
		(*first)->next = new;
		(*first) = save;
	}
}

void		print_u(va_list ap, print_list *lst)
{
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	ft_putnbr_unsi(i, 1);
	// printf("%d", i);
}

void		print_x(va_list ap, print_list *lst)
{
	char		*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	s = ft_itoa_hexa_unsi(i, "0123456789abcdef");
	ft_putstr_fd(s, 1);
	// printf("%d", i);
}

void		print_X(va_list ap, print_list *lst)
{
	char		*s;
	unsigned int		i;

	i = va_arg(ap, unsigned int);
	s = ft_itoa_hexa_unsi(i, "0123456789ABCDEF");
	ft_putstr_fd(s, 1);
	// printf("%d", i);
}

