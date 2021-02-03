/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:18:32 by ldenis            #+#    #+#             */
/*   Updated: 2021/02/03 14:49:49 by ldenis           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
int					ft_toupper(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_isalpha(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
int					ft_fatoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),\
void (*del)(void *));
char				*ft_ftstrncpy(char *src, unsigned int n);
int					ft_counter_word(const char *str, char set);
int					ft_iszero(int i);
int					conteur_malloc(int nbr, int size_base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_itoa_hexa_l(unsigned long n, char *base);
void				ft_putnbr_unsi(unsigned int n, int fd);
char				*ft_itoa_hexa_unsi(unsigned int n, char *base);
char				*ft_itoa_unsi(unsigned int n);
int					ft_strichr(const char *s, int c);
char				*ft_strcat(char *dest, char *src);

#endif
