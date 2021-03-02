/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2021/03/02 18:12:42 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			add_flag(t_print *lst, char *str, int start, va_list ap)
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
			lst->size = ft_fatoi(ft_substr(str, start, i));
		else
			lst->size_point = ft_fatoi(ft_substr(str, start, i));
		zero(lst, str, start);
		return (start + j);
	}
	return (start + 1);
}

void		point(t_print *lst, const char *str)
{
	int		i;

	i = 0;
	lst->flag_point = 1;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i + 1] == '.')
		lst->flag_0 = 1;
	i++;
	if (str[i] == '-' && str[i + 1] == '.')
		lst->flag_0 = 1;
}

void		zero(t_print *lst, const char *str, int i)
{
	i--;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i + 1] == '0')
		lst->flag_0 = 1;
}

void		fill_print(t_print *lst, int i)
{
	i = verif_fill(lst, i);
	while (i++ < lst->size_point)
	{
		if (lst->flag_0 == 1)
			lst->print = ft_strfjoin("0\0", lst->print, 2);
		else
			lst->print = ft_strfjoin(" \0", lst->print, 2);
		lst->index_b++;
	}
	i = verif(lst, i);
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
	if (lst->verif == 1)
		lst->print = ft_strfjoin("-\0", lst->print, 2);
	lst->index_b -= 2;
}

void		wildcard(t_print *lst, va_list ap)
{
	lst->flag_etoile = 1;
	if (lst->flag_point == 1)
	{
		lst->size_point = va_arg(ap, int);
		lst->second_wildcard = 1;
	}
	else
		lst->size = va_arg(ap, int);
	if (lst->size <= 0)
		lst->flag_tiret = 1;
	if (lst->size_point >= 1)
		lst->flag_0 = 1;
	else if (lst->flag_point == 1 && lst->size_point == 0)
		lst->flag_0 = 0;
}
