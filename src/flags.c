/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/14 12:18:08 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			add_flag(print_list *lst, const char *str, int start, va_list ap)
{
	int		i;
	int		j;
	char	c;

	i = start;
	c = str[i];
	j = 0;
	while (is_num(str[i++]) != 0 && str[i])
		j++;
	if (c == '-')
		lst->flag_tiret = 1;
	else if (c == '.')
		point(lst, str);
	else if (c == '*')
		wildcard(lst, ap);
	else
	{
		if (lst->flag_etoile == 0 && lst->flag_point == 0)
			lst->size = ft_atoi(ft_substr(str, start, i));
		else
			lst->size_point = ft_atoi(ft_substr(str, start, i));
		zero(lst, str);
		return (start + j);
	}
	return (start + 1);
}

void		point(print_list *lst, const char *str)
{
	int		i;

	i = 0;
	lst->flag_point = 1;
	if (lst->flag_point == 1 && lst->size > 0)
		lst->flag_0 = 1;
	if (lst->flag_etoile == 1 && lst->size_point == 0)
		lst->flag_0 = 1;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i + 1] == '.')
		lst->flag_0 = 1;
}

void		zero(print_list *lst, const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i + 1] == '0')
		lst->flag_0 = 1;
}

void		fill_print(print_list *lst)
{
	int		i;

	i = ft_strlen(lst->print);
	i = verif_fill(lst, i);
	if (lst->size != 0)
	{
		while (i++ < lst->size)
		{
			if (lst->flag_tiret == 1)
				lst->print = ft_strfjoin(lst->print, " \0", 1);
			else if (lst->flag_0 == 1)
				lst->print = ft_strfjoin("0\0", lst->print, 2);
			else
				lst->print = ft_strfjoin(" \0", lst->print, 2);
			lst->index_b++;
		}
		lst->index_b -= 2;
	}
	if (lst->verif == 1)
		verif(lst);
}

void		wildcard(print_list *lst, va_list ap)
{
	lst->flag_etoile = 1;
	if (lst->flag_point == 1)
		lst->size_point = va_arg(ap, int);
	else
		lst->size = va_arg(ap, int);
	if (lst->size < 0)
	{
		lst->size = lst->size * -1;
		lst->flag_tiret = 1;
	}
}
