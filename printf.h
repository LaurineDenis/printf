/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:58:55 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/14 09:51:52 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

int		ft_printf(const char *, ...);
void	print_c(va_list ap);
void	print_s(va_list ap);
void	print_d(va_list ap);

#endif
