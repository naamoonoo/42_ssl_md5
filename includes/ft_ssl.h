/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/04/25 16:13:26 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <stdio.h>

# include <math.h>

# include "../lib/libftprintf/includes/ft_printf.h"
# include "../lib/libftprintf/includes/libft.h"

# define E_FOLDER -9
# define E_INPUT -10
# define E_FLAG -11
# define E_USAGE -12
# define E_COMMAND -13

# define LEFT_ROTATE(n, d) ((n << d) | (n >> (32 - d)))
# define RIGHT_ROTATE(n, d) ((n >> d) | (n << (32 - d)))
# define RIGHT_ROTATE_64(n, d) ((n >> d) | (n << (64 - d)))

typedef	struct	s_flags
{
	int			p;
	int			q;
	int			r;
}				t_f;

typedef struct	s_ssl_dp
{
	char		*command;
	void		(*f)(char *);
}				t_sdp;

typedef struct	s_ssl
{
	t_sdp		dp;
	t_f			flags;
}				t_ssl;

typedef struct	s_md
{
	uint		A;
	uint		B;
	uint		C;
	uint		D;
	uint		a;
	uint		b;
	uint		c;
	uint		d;
	uint		f;
	uint		g;
	u_char		*n;
	u_char		m[16][4];
	uint		set;
}				t_md;

typedef struct	s_sha
{
	uint		H[8];
	uint		a;
	uint		b;
	uint		c;
	uint		d;
	uint		e;
	uint		f;
	uint		g;
	uint		h;
	u_char		*n;
	uint		w[64];
	uint		set;
}				t_sha;

typedef struct	s_sha5
{
	uint64_t	H[8];
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
	uint64_t	e;
	uint64_t	f;
	uint64_t	g;
	uint64_t	h;
	u_char		*n;
	uint64_t	w[80];
	uint64_t	set;
}				t_sha5;

void			handle_input(int i, int ac, char *av[], t_ssl *ssl);
int				get_command(char *cmd);
void			flag_handler(char c, t_ssl *ssl, int *ac);
void			stdin_mode(int ac, t_ssl *ssl);
void			file_mode(int fd, t_ssl *ssl, char *file);

void			md5_hash(char *s);

void			sha224_hash(char *s);
void			sha256_hash(char *s);
void			sha384_hash(char *s);
void			sha512_hash(char *s);

void			error_alert(int code, char *input);
void			error_exit(int code, char *input);
void			reverse_bits(uint *c);

static	t_sdp	g_ssl_dp[] =
{
	{"md5", md5_hash},
	{"sha224", sha224_hash},
	{"sha256", sha256_hash},
	{"sha384", sha384_hash},
	{"sha512", sha512_hash},
	{NULL, NULL}
};


#endif
