/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:38:21 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/19 13:46:01 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_print
{
	char			convert;
	int				flag_0;
	int				flag_tiret;
	int				flag_point;
	int				flag_etoile;
	int				second_wildcard;
	int				size;
	int				size_point;
	int				verif;
	int				backslash;
	int				index_b;
	char			*print;
	struct s_print	*next;
}					t_print;

int					ft_printf(const char *str, ...);
void				print_c(va_list ap, t_print *lst, char *str);
void				print_s(va_list ap, t_print *lst, char *str);
void				print_d_i(va_list ap, t_print *lst, char *str);
void				print_bigx(va_list ap, t_print *lst, char *str);
void				print_x(va_list ap, t_print *lst, char *str);
void				print_u(va_list ap, t_print *lst, char *str);
void				print_p(va_list ap, t_print *lst, char *str);
void				print_per(va_list ap, t_print *lst, char *str);
char				*parse(char	*ret, char *str, t_print **lst, va_list ap);
t_print				*init_struct(void);
t_print				*add_back_lst(t_print **first, t_print *last);
void				init_tab(void (*grid[121])(va_list, t_print *, char *));
char				*ft_strfjoin(char *s1, char *s2, int is_free);
int					add_flag(t_print *lst, char *str, int start, va_list ap);
int					is_c(char c);
int					is_f(char c);
int					is_num(char c);
void				tiret(t_print *lst);
void				size(t_print *lst);
void				fill_print(t_print *lst, int i);
void				zero(t_print *lst, const char *str, int i);
void				wildcard(t_print *lst, va_list ap);
void				point(t_print *lst, const char *str);
int					verif(t_print *lst, int i);
void				backslash(t_print *lst, char *str);
int					aff_zero(t_print *lst, char *ret, size_t len);
int					verif_fill(t_print *lst, int i);
int					verif_percent(t_print *lst, int i);
int					aff_printf(int len, int aff, char *ret, int i);
char				*parsing(int i, const char *str, t_print **lst, va_list ap);
void				lst_free(t_print **lst);
int					back200(t_print *lst, char *ret);
int					test(t_print *lst, int i);

#endif
