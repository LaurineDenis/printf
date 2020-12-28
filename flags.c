/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/28 17:13:15 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		add_flag(print_list *lst, char c, const char *str, int start)
{
	int		i;
	int		j;

	i = start;
	while ( && str[i])
		{
			i++;
		}
	j = i - start;
	printf("j = %d\n", j);
	printf("i = %d\n", i);
	printf("start = %d\n", start);
	if (c == '-')
		tiret(lst);
	else if (c == '.')
		lst->flag_point = 1;
	else if (c == '*')
		lst->flag_etoile = 1;
	else
	{
		// dprintf(1, "sortie 1\n");
		lst->taille = ft_atoi(ft_substr(str, start, i));
		dprintf(1, "taile = %d\n", lst->taille);
		return (start + j);
	}
	return (start);
}

void	tiret(print_list *lst)
{
	lst->flag_tiret = 1;
	if (!(lst->print = ft_strfjoin(lst->print, "-\0", 1)))
		return ;
	// printf("tiret = %s\n", lst->print);
}

void	size(print_list *lst)
{
	if (lst->taille == 0)
		lst->taille = ft_strlen(lst->print);
}
