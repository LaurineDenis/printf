/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/07 18:26:42 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_flag(print_list *lst, char c, const char *str, int start, va_list ap)
{
	int		i;
	int		j;

	i = start;
	j = 0;
	while (is_num(str[i]) != 0 && str[i])
	{
		j++;
		i++;
	}
	if (c == '-')
		lst->flag_tiret = 1;
	else if (c == '.')
		point(lst, str);
	else if (c == '*')
		wildcard(lst, ap);
	else if (lst->flag_point == 0)
	{
		if (lst->flag_etoile == 0)
			lst->size = ft_atoi(ft_substr(str, start, i));
		zero(lst, str);
		return (start + j);
	}
	else
	{
		lst->size_point = ft_atoi(ft_substr(str, start, i));
		zero(lst, str);
		return (start + j);
	}
	return (start + 1);
}

void	point(print_list *lst, const char *str)
{
	int		i;

	i = 0;
	lst->flag_point = 1;
	if (lst->flag_etoile == 1 && lst->size_point == 0)
		lst->flag_0 = 1;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i + 1] == '.')
		lst->flag_0 = 1;
}

void	zero(print_list *lst, const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	// printf("i = %zu\n", i);
	if (str[i + 1] == '0')
		lst->flag_0 = 1;
}

void	fill_print(print_list *lst)
{
	int		i;
	
	if (lst->convert == '%')
		lst->size_point = 1;
	if (lst->size_point == 0)
		lst->flag_0 = 0;
	if (lst->size < lst->size_point)
		lst->size = lst->size_point;
	// printf("print fill = %s\n", lst->print);
	if (lst->size != 0)
	{
		i = ft_strlen(lst->print);
		while (i++ < lst->size)
		{
			if (lst->flag_tiret == 1)
				lst->print = ft_strfjoin(lst->print, " \0", 1);
			else if (lst->flag_0 == 1)
				lst->print = ft_strfjoin("0\0", lst->print, 2);
			else
				lst->print = ft_strfjoin(" \0", lst->print, 2);
		}
	}
	if (lst->verif == 1)
	{
		if ((lst->flag_point == 0 && lst->convert == 'i') || (lst->convert == 'd' && lst->flag_point == 0))
			lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
		lst->print = ft_strfjoin("-\0", lst->print, 2);
	}
}

int		is_num(char c)
{
	char	*num;
	int		i;

	num = "0123456789";
	i = 0;
	while (num[i])
	{
		if (num[i] == c)
			return (1);
		i++;
	}
	return (0);
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