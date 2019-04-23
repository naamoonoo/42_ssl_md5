#include "ft_ssl.h"

uint	g_sha256_k[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
	0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138,
	0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
	0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f,
	0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

uint	g_sha256_iv[8] =
{
	0x6a09e667,
	0xbb67ae85,
	0x3c6ef372,
	0xa54ff53a,
	0x510e527f,
	0x9b05688c,
	0x1f83d9ab,
	0x5be0cd19
};

void	sha256_loop(int i, t_sha *sha)
{
	uint	S0;
	uint	S1;
	uint	ch;
	uint	temp1;
	uint	maj;

	S1 = RIGHT_ROTATE(sha->e, 6) ^ RIGHT_ROTATE(sha->e, 11)
		^ RIGHT_ROTATE(sha->e, 25);
	ch = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
	temp1 = sha->h + S1 + ch + g_sha256_k[i] + sha->w[i];
	S0 = RIGHT_ROTATE(sha->a, 2) ^ RIGHT_ROTATE(sha->a, 13)
		^ RIGHT_ROTATE(sha->a, 22);
	maj = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
	sha->h = sha->g;
	sha->g = sha->f;
	sha->f = sha->e;
	sha->e = sha->d + temp1;
	sha->d = sha->c;
	sha->c = sha->b;
	sha->b = sha->a;
	sha->a = temp1 + S0 + maj;
}

void	sha256_pre(int set, t_sha *sha)
{
	int		i;
	uint	s0;
	uint	s1;

	i = -1;
	while (++i < 16)
	{
		sha->w[i] = (sha->n[set * 64 + i * 4] << 24)
		+ (sha->n[set * 64 + i * 4 + 1] << 16)
		+ (sha->n[set * 64 + i * 4 + 2] << 8)
		+ (sha->n[set * 64 + i * 4 + 3]);
	}
	i = 15;
	while (++i < 64)
	{
		s0 = RIGHT_ROTATE(sha->w[i - 15], 7) ^ RIGHT_ROTATE(sha->w[i - 15], 18)
			^ (sha->w[i - 15] >> 3);
		s1 = RIGHT_ROTATE(sha->w[i - 2], 17) ^ RIGHT_ROTATE(sha->w[i - 2], 19)
			^ (sha->w[i - 2] >> 10);
		sha->w[i] = sha->w[i - 16] + s0 + sha->w[i - 7] + s1;
	}
}

void	sha256_process(int set, t_sha *sha)
{
	int i;

	sha256_pre(set, sha);
	sha->a = sha->H[0];
	sha->b = sha->H[1];
	sha->c = sha->H[2];
	sha->d = sha->H[3];
	sha->e = sha->H[4];
	sha->f = sha->H[5];
	sha->g = sha->H[6];
	sha->h = sha->H[7];
	i = -1;
	while (++i < 64)
		sha256_loop(i, sha);
	sha->H[0] += sha->a;
	sha->H[1] += sha->b;
	sha->H[2] += sha->c;
	sha->H[3] += sha->d;
	sha->H[4] += sha->e;
	sha->H[5] += sha->f;
	sha->H[6] += sha->g;
	sha->H[7] += sha->h;
}

void	sha256_init(char *s, t_sha *sha)
{
	uint		i;
	uint64_t	bit_len;

	i = -1;
	while (++i < 8)
		sha->H[i] = g_sha256_iv[i];
	sha->set = (ft_strlen(s) + 8) / 64 + 1;
	sha->n = (unsigned char *)malloc(64 * sha->set);
	i = -1;
	while (++i < 64 * sha->set)
		sha->n[i] = 0;
	i = -1;
	while (s[++i])
		sha->n[i] = s[i];
	sha->n[i] = 1 << 7;
	bit_len = i << 3;
	i = -1;
	while (++i < 8)
		sha->n[64 * sha->set - i - 1] = ((char*)(&bit_len))[i];
}

void	sha256_hash(char *s)
{
	t_sha	sha;
	uint	set;

	sha256_init(s, &sha);
	set = -1;
	while (++set < sha.set)
		sha256_process(set, &sha);
	set = -1;
	while (++set < 8)
		FP("%.8x", sha.H[set]);
	free(sha.n);
}
