/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:51:18 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/14 14:21:33 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		in_find_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if ((base[i] == 45) || (base[i] == 43) || (base[i] == 32))
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		i++;
		j = i + 1;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int			i;
	int			j;
	long int	ret;
	int			size;

	i = 0;
	j = 1;
	ret = 0;
	size = check_base(base);
	if (size < 1)
		return (0);
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			j *= (-1);
		i++;
	}
	while (in_find_base(str[i], base) >= 0)
	{
		ret = ((ret * size) + (in_find_base(str[i], base)));
		i++;
	}
	return (ret * j);
}

char	*itoa_base(char *nombre, long int nbr, char *base, int i)
{
	if (nbr < 0)
	{
		nombre[0] = '-';
		nbr *= (-1);
	}
	if (nbr >= check_base(base))
		itoa_base(nombre, (nbr / check_base(base)), base, i - 1);
	nombre[i] = base[nbr % check_base(base)];
	return (nombre);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				size_to;
	int				size_from;
	long int		nbr_1;
	int				j;
	char			*nombre;

	nbr_1 = ft_atoi_base(nbr, base_from);
	size_to = check_base(base_to);
	size_from = check_base(base_from);
	if (size_to <= 1 || size_from <= 1)
		return (0);
	j = conteur_malloc(nbr_1, size_to);
	if (!(nombre = (char*)malloc(sizeof(char) * j + 1)))
		return (0);
	if (nbr_1 == 0)
	{
		nombre[0] = base_to[0];
		nombre[1] = '\0';
		return (nombre);
	}
	nombre = itoa_base(nombre, nbr_1, base_to, j - 1);
	nombre[j] = '\0';
	return (nombre);
}
