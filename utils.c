/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:51:30 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/12 15:43:13 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strfjoin(char *s1, char *s2, int is_free)
{
	size_t		len;
	char		*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	ft_memcpy((void *)str, (const void *)s1, ft_strlen(s1));
	ft_strlcat((char *)str, (char *)s2, len + 2);
	if (is_free == 1)
		free(s1);
	else if (is_free == 2)
		free(s2);
	else if (is_free != 0)
	{
		free(s1);
		free(s2);
	}
	return (str);
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

void	verif(print_list *lst)
{
	if (lst->flag_point == 0 && lst->convert == 'i')
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	if (lst->convert == 'd' && lst->flag_point == 0)
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	lst->print = ft_strfjoin("-\0", lst->print, 2);
}

char		*parse(char	*ret, const char *str, print_list **lst, va_list ap)
{
	void		(*tab_fonction[121])(va_list, print_list *, char *);
	print_list	*beg;
	size_t		i;

	i = 0;
	init_tab(tab_fonction);
	beg = (*lst);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			// dprintf(1, "adresse = %p\n", &lst);
			add_back_lst(lst, init_struct());
			while (is_c(str[i]) != 0 || is_f(str[i]) != 0)
			{
				if (is_c(str[i]) != 0)
				{
					(*lst)->convert = str[i];
					(tab_fonction[(int)str[i]])(ap, *lst, (char *)str);
					fill_print(*lst);
					ret = ft_strfjoin(ret, (*lst)->print, 1);
					i++;
					break ;
				}
				i = add_flag(*lst, str, i, ap);
			}
				// dprintf(1, "-----------NEW FLAG-----------\n");
				// dprintf(1, "convert = %c\n", (*lst)->convert);
				// dprintf(1, "adresse = %p\n", (*lst));
				// dprintf(1, "flag_0 = %d\n", (*lst)->flag_0);
				// dprintf(1, "flag_point = %d\n", (*lst)->flag_point);
				// dprintf(1, "flag_etoile = %d\n", (*lst)->flag_etoile);
				// dprintf(1, "flag_tiret = %d\n", (*lst)->flag_tiret);
				// dprintf(1, "backslash = %d\n", (*lst)->backslash);
				// dprintf(1, "verif = %d\n", (*lst)->verif);
				// dprintf(1, "size = %d\n", (*lst)->size);
				// dprintf(1, "size_point = %d\n", (*lst)->size_point);
				// dprintf(1, "print = %s\n", (*lst)->print);
		}
		if (str[i] == '%')
			continue ;
		ret = ft_strfjoin(ret, ft_substr(str, i, 1), 3);
		i++;
	}
	if ((*lst)->next != NULL)
		(*lst) = beg;
	else
		(*lst) = beg->next;
	return (ret);
}
