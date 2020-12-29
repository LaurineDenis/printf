/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:46 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/29 15:58:55 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		lst->flag_point = 1;
	else if (c == '*')
		wildcard(lst, ap);
	else
	{
		if (lst->flag_etoile == 0)
			lst->taille = ft_atoi(ft_substr(str, start, i));
		zero(lst, ft_substr(str, start, ft_strlen(str)));
		return (start + j);
	}
	zero(lst, ft_substr(str, start, ft_strlen(str)));
	return (start + 1);
}

void	zero(print_list *lst, const char *str)
{
	size_t		i;

	i = 0;
	if (lst->taille == 0)
		return ;
	while (str[i] != 0 && is_f(str[i]) != 0)
		i++;
	if (i != ft_strlen(str))
		lst->flag_0 = 1;
}

void	fill_print(print_list *lst)
{
	int		i;

	if (lst->taille == 0)
		lst->taille = ft_strlen(lst->print);
	else if (lst->flag_tiret == 1)
	{
		i = ft_strlen(lst->print);
		while (i++ < lst->taille)
			lst->print = ft_strfjoin(lst->print, " \0", 1);
	}
	else
	{
		i = ft_strlen(lst->print);
		while (i++ < lst->taille)
		{
			if (lst->flag_0 == 1)
				lst->print = ft_strfjoin("0\0", lst->print, 2);
			else
				lst->print = ft_strfjoin(" \0", lst->print, 2);
		}
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
	lst->taille = va_arg(ap, int);
	if (lst->taille < 0)
		lst->taille = lst->taille * -1;
}
