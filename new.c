/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:20:39 by laurinedeni       #+#    #+#             */
/*   Updated: 2021/01/07 16:37:46 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     new_printf(print_list *lst)
{
    int     i;
    int     j;
    char    *ret;
    char    *fill;

    i = lst->size_point - ft_strlen(lst->print);
    j = 0;
    fill = (lst->flag_0 == 1) ? "0\0" : " \0";
    while (j++ < i)
        ret[j] = fill[0];
    if (lst->flag_tiret == 1)
        lst->print = ft_strfjoin(lst->print, " \0", 1);
    else
        lst->print = ft_strfjoin(ret, lst->print, 2);
    
}