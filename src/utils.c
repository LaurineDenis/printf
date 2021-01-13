/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:51:30 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/13 12:37:29 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strfjoin(char *s1, char *s2, int is_free)
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

int			is_num(char c)
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

void		verif(print_list *lst)
{
	if (lst->flag_point == 0 && lst->convert == 'i')
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	if (lst->convert == 'd' && lst->flag_point == 0)
		lst->print = ft_substr(lst->print, 1, ft_strlen(lst->print));
	lst->print = ft_strfjoin("-\0", lst->print, 2);
}
