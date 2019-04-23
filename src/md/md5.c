/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:10:08 by hnam              #+#    #+#             */
/*   Updated: 2019/04/23 11:56:12 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint	g_md5_r[64] =
{
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

uint	g_md5_k[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void	md5_loop(int i, t_md *md)
{
	if (0 <= i && i < 16)
	{
		md->f = (md->b & md->c) | ((~md->b) & md->d);
		md->g = i;
	}
	else if (16 <= i && i < 32)
	{
		md->f = (md->d & md->b) | ((~md->d) & md->c);
		md->g = (5 * i + 1) % 16;
	}
	else if (32 <= i && i < 48)
	{
		md->f = md->b ^ md->c ^ md->d;
		md->g = (3 * i + 5) % 16;
	}
	else
	{
		md->f = md->c ^ (md->b | (~md->d));
		md->g = (7 * i) % 16;
	}
	md->f += md->a + g_md5_k[i] + *((uint*)(md->m[md->g]));
	md->a = md->d;
	md->d = md->c;
	md->c = md->b;
	md->b += LEFT_ROTATE(md->f, g_md5_r[i]);
}

void	md5_process(int set, t_md *md)
{
	int i;
	int j;

	i = -1;
	while (++i < 16)
	{
		j = -1;
		while (++j < 4)
			md->m[i][j] = md->n[set * 64 + i * 4 + j];
	}
	md->a = md->A;
	md->b = md->B;
	md->c = md->C;
	md->d = md->D;
	i = -1;
	while (++i < 64)
		md5_loop(i, md);
	md->A += md->a;
	md->B += md->b;
	md->C += md->c;
	md->D += md->d;
}

void	md5_init(char *s, t_md *md)
{
	uint		i;
	uint64_t	bit_len;

	md->A = 0x67452301;
	md->B = 0xefcdab89;
	md->C = 0x98badcfe;
	md->D = 0x10325476;
	md->f = 0;
	md->g = 0;
	md->set = (ft_strlen(s) + 8) / 64 + 1;
	md->n = (unsigned char *)malloc(64 * md->set);
	i = -1;
	while (++i < 64 * md->set)
		md->n[i] = 0;
	i = -1;
	while (s[++i])
		md->n[i] = s[i];
	md->n[i] = 1 << 7;
	bit_len = i << 3;
	i = -1;
	while (++i < 8)
		md->n[64 * md->set - 8 + i] = ((char*)(&bit_len))[i];
}

void	md5_hash(char *s)
{
	t_md	md;
	uint	set;

	md5_init(s, &md);
	set = -1;
	while (++set < md.set)
		md5_process(set, &md);
	reverse_bits(&md.A);
	reverse_bits(&md.B);
	reverse_bits(&md.C);
	reverse_bits(&md.D);
	FP("%.8x%.8x%.8x%.8x", md.A, md.B, md.C, md.D);
	free(md.n);
}
