/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:58:55 by ldenis            #+#    #+#             */
/*   Updated: 2021/01/07 16:36:45 by laurinedeni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct			print_list
{
	char				convert;
	int					flag_0;
	int					flag_tiret;
	int					flag_point;
	int					flag_etoile;
	int					size;
	int					size_point;
	int					verif;
	int					backslash;
	int					index_b;
	char				*print;
	struct print_list	*next;
}						print_list;

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

int			ft_printf(const char *, ...);
void		print_c(va_list ap, print_list *lst, char *str);
void		print_s(va_list ap, print_list *lst, char *str);
void		print_d_i(va_list ap, print_list *lst, char *str);
void		print_bigx(va_list ap, print_list *lst, char *str);
void		print_x(va_list ap, print_list *lst, char *str);
void		print_u(va_list ap, print_list *lst, char *str);
void		print_p(va_list ap, print_list *lst, char *str);
void		print_per(va_list ap, print_list *lst, char *str);
char		*parse(char	*ret, const char *str, print_list **lst, va_list ap);
print_list	*init_struct(void);
void		add_back_lst(print_list **first, print_list *new);
void		init_tab(void (*grid[121])(va_list, print_list *, char *));
char		*ft_strfjoin(char *s1, char *s2, int is_free);
int			add_flag(print_list *lst, const char *str, int start, va_list ap);
int			is_c(char c);
int			is_f(char c);
int			is_num(char c);
void		tiret(print_list *lst);
void		size(print_list *lst);
void		fill_print(print_list *lst);
void		zero(print_list *lst, const char *str);
void		wildcard(print_list *lst, va_list ap);
void		point(print_list *lst, const char *str);
void		verif(print_list *lst);
void		backslash(print_list *lst, char *str);
int			aff_zero(print_list *lst, char *ret, size_t len);
int			verif_fill(print_list *lst, int i);
int			aff_printf(print_list *lst, int len, int aff, char *ret);
char		*parsing(int i, const char *str, print_list **lst, va_list ap);
void		lst_free(print_list **lst);

#endif
