/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:16:22 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/12 17:26:39 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list ap, print_list *lst, char *str)
{
	char	c;
	char	s[2];

	c = (char)va_arg(ap, int);
	s[0] = c;
	s[1] = '\0';
	if (!c)
	{
		lst->backslash = 1;
		backslash(lst, str);
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}

void	print_s(va_list ap, print_list *lst, char *str)
{
	char	*s;

	s = va_arg(ap, char *);
	(void)str;
	if (!s)
	{
		s = "(null)";
		if (lst->flag_point == 1)
		{
			s = ft_substr(s, 0, lst->size_point);
			if ((size_t)lst->size_point > ft_strlen(s))
				lst->size_point = ft_strlen(s);
		}
	}
	if (lst->flag_point == 1)
	{
		s = ft_substr(s, 0, lst->size_point);
		if ((size_t)lst->size_point > ft_strlen(s))
			lst->size_point = ft_strlen(s);
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	if (lst->flag_point == 1)
		free(s);
}

void	print_d_i(va_list ap, print_list *lst, char *str)
{
	int		i;
	char	*ret;

	i = va_arg(ap, int);
	(void)str;
	ret = ft_itoa(i);
	if (i == 0 && lst->flag_point == 1)
	{
		if (lst->size == 0 && lst->size_point == 0)
		{
			lst->print = ft_calloc(1, 1);
			free(ret);
			return ;
		}
	}
	if (!(lst->print = ft_strfjoin(lst->print, ret, 1)))
		return ;
	if (i < 0 && lst->flag_0 == 1 && lst->flag_point == 1)
	{
		if (lst->size_point <= 1)
			return ;
		lst->verif = 1;
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	}
	free(ret);
}

void	print_p(va_list ap, print_list *lst, char *str)
{
	char					*s;
	long long int			i;

	i = va_arg(ap, long long int);
	(void)str;
	s = ft_itoa_hexa_l(i, "0123456789abcdef");
	if (lst->flag_point == 0 && (!s || ft_strlen(s) == 0))
		s = "0\0";
	if (!(lst->print = ft_strfjoin(lst->print, "0x", 1)))
		return ;
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}

void	print_u(va_list ap, print_list *lst, char *str)
{
	unsigned int		i;
	char				*ret;

	i = va_arg(ap, unsigned int);
	(void)str;
	ret = ft_itoa_unsi(i);
	if (i == 0)
		ret = "0\0";
	if (i == 0 && lst->size == 0)
	{
		if (lst->size_point == 0 && lst->flag_point == 1)
			return ;
	}
	if (!(lst->print = ft_strfjoin(lst->print, ret, 1)))
		return ;
}
