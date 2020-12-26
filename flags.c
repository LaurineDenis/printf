/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/26 14:43:39 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		add_flag(print_list *lst, char c, const char *str, int start)
{
	int		i;

	i = 0;
	while (is_c(str[i]) == 0 && str[i])
		i++;
	if (c == '-')
		tiret(lst);
	else if (c == '.')
		lst->flag_point = 1;
	else if (c == '*')
		lst->flag_etoile = 1;
	else
	{
		lst->taille = ft_atoi(ft_substr(str, start, i));
		return (start + i - 2);
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

