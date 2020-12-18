/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/18 15:31:49 by ldenis           ###   ########lyon.fr   */
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
		lst->flag_tiret = 1;
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
