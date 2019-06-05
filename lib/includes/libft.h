/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 23:24:35 by hnam              #+#    #+#             */
/*   Updated: 2019/06/05 12:07:30 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>

# define BUFF_SIZE 32
# define MAX_FD 10000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**---------------------macro---------------------
*/

# define ABS(x) ((x) < 0 ? (x) * -1 : (x))
# define MAX_INT -2147483648
# define IS_EXIST(x) ((x) ? 1 : 0)
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

/*
**---------------------memory handling---------------------
*/

void				*ft_memset(void *b, int i, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
**---------------------string descriptor---------------------
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
int					ft_start_idx(char const *s);
void				ft_ulstr(char c);
int					ft_hidenp(char *s1, char *s2);
int					ft_strchr_idx(const char *s, int c);
char				*ft_strtrim_by(char const *s, char condition);
char				*ft_strjoin_by(char const *s1, char const *s2, char *c);
char				*ft_str_upper(char *s);
char				*ft_str_lower(char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**---------------------number descriptor---------------------
*/

void				ft_putnbr(int64_t n);
void				ft_putnbr_u(uint64_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int str_base);
int					ft_numlen(uint64_t n, uint64_t base);
int64_t				ft_pow(int64_t base, int times);
uint64_t			ft_pow_u(uint64_t base, int times);
int					ft_pgcd(int a, int b);
void				itoa_minus_hande(int64_t *n, char *res, int *len, int *i);
char				*ft_itoa(int n);
char				*ft_itoa_base(int64_t n, int str_base, int len);
char				*ft_itoa_base_u(uint64_t n, int str_base, int len);
int					get_big(int a, int b);
int					get_small(int a, int b);
long				ft_atol(const char *str);
void				ft_n_swap(int *a, int *b);



/*
**---------------------checking---------------------
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_is_space(char c);
int					ft_start_with(char *s, char c);

/*
**---------------------file descriptor---------------------
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**---------------------list handling---------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**---------------------get next line---------------------
*/

int					get_next_line(const int fd, char **line);
int					get_file(int fd, char **file);


#endif
