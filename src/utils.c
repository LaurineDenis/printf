/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:51:30 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/03 14:34:20 by ldenis           ###   ########lyon.fr   */
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
	else if (is_free == 3)
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

int			is_c(char c)
{
	char	*convert;
	int		i;

	convert = "csdpuixX%";
	i = 0;
	while (convert[i])
	{
		if (convert[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int			is_f(char c)
{
	char	*flag;
	int		i;

	flag = "-.*0123456789";
	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (flag[i]);
		i++;
	}
	return (0);
}
