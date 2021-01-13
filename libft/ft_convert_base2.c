/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:58:34 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/28 13:58:49 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		conteur_malloc(int nbr, int size_base)
{
	int conteur;

	conteur = 0;
	if (nbr < 0)
		conteur++;
	while (nbr != 0)
	{
		nbr /= size_base;
		conteur++;
	}
	return (conteur);
}
