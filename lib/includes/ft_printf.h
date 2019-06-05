/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:17:47 by hnam              #+#    #+#             */
/*   Updated: 2019/04/22 16:01:45 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define ERROR -42

# define FLAG_SPECIFIER "-+ 0#.123456789$*"
# define LENGTH_SPECIFIER "hlL"
# define SPECIFIER "cspdiouxXfbeEgGaABn%"
# define KIND_OF_SPECIFIER (ft_strlen(SPECIFIER))

# define BINARY 2
# define OCTAL 8
# define HEXA 16

# define FLOAT_BIAS 127
# define DOUBLE_BIAS 1023
# define LONG_DOUBLE_BIAS 16383

# define FLOAT_LEN 32
# define DOUBLE_LEN 64
# define LONG_DOUBLE_LEN 80

# define FP ft_printf

enum			e_length
{
	h_LENGTH = 1 << 0,
	hh_LENGTH = 1 << 1,
	l_LENGTH = 1 << 2,
	ll_LENGTH = 1 << 3,
	L_LENGTH = 1 << 4,
};

typedef struct	s_dispatch_table
{
	char		specifier;
	int			(*function)();
}				t_dt;

typedef struct	s_flag_specifier
{
	int			plus;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			width;
	int			w_star;
	int			p_star;
	int			dot;
	int			prec;
	int			length;
	int			is_upper;
	int			is_g;
}				t_s;

typedef struct	s_color_table
{
	char		*color;
	char		*code;
}				t_table;

int				ft_printf(char *s, ...);
int				ft_printf_fd(int fd, ...);

void			ft_formatting(char **s, va_list *ap, int *res);
void			flag_setting(t_s *fs);
int				get_length(char **s, t_s *fs);
int				get_format(char **s, int *flag, t_s *fs);
void			get_flag(char c, t_s *fs);

int				c_print(va_list *ap, t_s fs);
int				s_print(va_list *ap, t_s fs);
int				p_print(va_list *ap, t_s fs);
int				pct_print(t_s fs);

int64_t			get_number(va_list *ap, t_s fs);
int				di_print(va_list *ap, t_s fs);

uint64_t		get_unsigned_number(va_list *ap, t_s fs);
int				u_print(va_list *ap, t_s fs);
void			ft_putnbr_width_u(uint64_t n, int minimum_len, t_s fs);

int				o_print(va_list *ap, t_s fs);
int				x_print(va_list *ap, t_s fs);
int				b_print(va_list *ap, t_s fs);

long double		get_float_number(va_list *ap, t_s fs);
int				f_print(va_list *ap, t_s fs);
int				e_print(va_list *ap, t_s fs);
int				g_print(va_list *ap, t_s fs);

int				ieee754_print(va_list *ap, t_s fs);
char			*ftob(long double n, int size, int bias);
char			*normalized_float_number(long double n, int size);

int				a_print(va_list *ap, t_s fs);
char			*btox(char *b);

void			ft_coloring(char **s, int *res);

int				length_print(va_list *ap);

int				is_sign(int is_minus, t_s fs);
void			sign_handler(int is_minus, t_s fs);
void			ft_putnbr_width(int64_t n, int minimum_len, t_s fs);
void			ft_put_float(long double n, t_s fs);
void			ft_put_expo(int e_num, t_s fs);

void			ft_make_width(int len, char c);
void			ft_putstr_upper(char *s);
int				get_enum(long double f);
void			star_handler(va_list *ap, t_s *fs);

#endif
