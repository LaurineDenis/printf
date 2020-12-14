/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:23:52 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/14 16:24:26 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_unsi(unsigned int n, int fd)
{
	unsigned int		b;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	b = n % 10;
	b = '0' + b;
	write(fd, &b, 1);
}
