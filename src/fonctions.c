/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:16:22 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/15 16:26:11 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(va_list ap, t_print *lst, char *str)
{
	char	c;
	char	s[2];

	c = (char)va_arg(ap, int);
	(void)str;
	s[0] = c;
	s[1] = '\0';
	if (!c)
	{
		lst->backslash = 1;
		s[0] = '\200';
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
}

void	print_s(va_list ap, t_print *lst, char *str)
{
	char	*s;
	int		to_free;

	s = va_arg(ap, char *);
	(void)str;
	to_free = !s ? 1 : 0;
	if (!s)
		s = "(null)";
	if (lst->flag_point == 1)
	{
		s = ft_substr(s, 0, lst->size_point);
		if ((size_t)lst->size_point > ft_strlen(s))
			lst->size_point = ft_strlen(s);
	}
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	if (lst->flag_point == 1 && lst->size > 0)
		lst->flag_0 = 0;
	if (lst->flag_point == 1)
		free(s);
}

void	print_d_i(va_list ap, t_print *lst, char *str)
{
	int		i;
	char	*ret;
	char	*save;

	i = va_arg(ap, int);
	(void)str;
	if (i == 0 && lst->flag_point == 1 && lst->size_point == 0)
		return ;
	ret = ft_itoa(i);
	if (!(lst->print = ft_strfjoin(lst->print, ret, 3)))
		return ;
	if (i < 0)
	{
		lst->verif = 1;
		save = ft_substr(lst->print, 1, ft_strlen(lst->print));
		free(lst->print);
		lst->print = save;
	}
}

void	print_p(va_list ap, t_print *lst, char *str)
{
	char					*s;
	long long int			i;

	i = va_arg(ap, long long int);
	(void)str;
	s = ft_itoa_hexa_l(i, "0123456789abcdef");
	if (lst->flag_point == 0 && (!s || ft_strlen(s) == 0))
	{
		free(s);
		s = ft_calloc(1, 1);
		s[0] = '0';
	}
	if (!(lst->print = ft_strfjoin(lst->print, "0x", 1)))
		return ;
	if (!(lst->print = ft_strfjoin(lst->print, s, 1)))
		return ;
	free(s);
}

void	print_u(va_list ap, t_print *lst, char *str)
{
	unsigned int		i;
	char				*ret;

	i = va_arg(ap, unsigned int);
	(void)str;
	ret = ft_itoa_unsi(i);
	if (i == 0)
	{
		free(ret);
		ret = "0\0";
		if (lst->size_point == 0)
		{
			if (lst->flag_point == 1)
			{
				return ;
			}
		}
	}
	if (!(lst->print = ft_strfjoin(lst->print, ret, 1)))
		return ;
	if (i != 0)
		free(ret);
}
