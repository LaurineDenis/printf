/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:58:55 by ldenis            #+#    #+#             */
/*   Updated: 2020/12/29 15:59:19 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

typedef struct			print_list
{
	char				convert;
	int					flag_0;
	int					flag_tiret;
	int					flag_point;
	int					flag_etoile;
	int					taille;
	char				*print;
	struct print_list	*next;
}						print_list;

#include <stdarg.h>
#include <stdio.h>
#include "lib/libft.h"

int			ft_printf(const char *, ...);
void		print_c(va_list ap, print_list *lst);
void		print_s(va_list ap, print_list *lst);
void		print_d_i(va_list ap, print_list *lst);
void		print_X(va_list ap, print_list *lst);
void		print_x(va_list ap, print_list *lst);
void		print_u(va_list ap, print_list *lst);
void		print_p(va_list ap, print_list *lst);
print_list	*init_struct(void);
void		add_back_lst(print_list **first, print_list *new);
void		init_tab(void (**tab_fonction)(va_list, print_list *));
char		*ft_strfjoin(char *s1, char *s2, int is_free);
int			add_flag(print_list *lst, char c, const char *str, int start, va_list ap);
int			is_c(char c);
int			is_f(char c);
int			is_num(char c);
void		tiret(print_list *lst);
void		size(print_list *lst);
void		fill_print(print_list *lst);
void		zero(print_list *lst, const char *str);
void		wildcard(print_list *lst, va_list ap);

#endif
