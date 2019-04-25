#include "ft_ssl.h"

uint64_t	g_sha512_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe,
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab,
	0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
	0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6,
	0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

uint64_t	g_sha512_iv[8] =
{
	0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
	0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
};

static void	sha512_loop(int i, t_sha5 *sha)
{
	uint64_t	S0;
	uint64_t	S1;
	uint64_t	ch;
	uint64_t	temp1;
	uint64_t	maj;

	S1 = RIGHT_ROTATE_64(sha->e, 14) ^ RIGHT_ROTATE_64(sha->e, 18)
		^ RIGHT_ROTATE_64(sha->e, 41);
	ch = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
	temp1 = sha->h + S1 + ch + g_sha512_k[i] + sha->w[i];
	S0 = RIGHT_ROTATE_64(sha->a, 28) ^ RIGHT_ROTATE_64(sha->a, 34)
		^ RIGHT_ROTATE_64(sha->a, 39);
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

static void	sha512_pre(int set, t_sha5 *sha)
{
	int			i;
	int			j;
	uint64_t	s0;
	uint64_t	s1;

	i = -1;
	while (++i < 16)
	{
		j = -1;
		sha->w[i] = 0;
		while (++j < 8)
			sha->w[i] += sha->n[set * 80 + i * 8 + j] << (8 * (7 - j));
	}
	i = 15;
	while (++i < 80)
	{
		s0 = RIGHT_ROTATE_64(sha->w[i - 15], 1) ^ RIGHT_ROTATE_64(sha->w[i - 15], 8)
			^ (sha->w[i - 15] >> 7);
		s1 = RIGHT_ROTATE_64(sha->w[i - 2], 19) ^ RIGHT_ROTATE_64(sha->w[i - 2], 61)
			^ (sha->w[i - 2] >> 6);
		sha->w[i] = sha->w[i - 16] + s0 + sha->w[i - 7] + s1;
	}
}

static void	sha512_process(int set, t_sha5 *sha)
{
	int i;

	sha512_pre(set, sha);
	sha->a = sha->H[0];
	sha->b = sha->H[1];
	sha->c = sha->H[2];
	sha->d = sha->H[3];
	sha->e = sha->H[4];
	sha->f = sha->H[5];
	sha->g = sha->H[6];
	sha->h = sha->H[7];
	i = -1;
	while (++i < 80)
		sha512_loop(i, sha);
	sha->H[0] += sha->a;
	sha->H[1] += sha->b;
	sha->H[2] += sha->c;
	sha->H[3] += sha->d;
	sha->H[4] += sha->e;
	sha->H[5] += sha->f;
	sha->H[6] += sha->g;
	sha->H[7] += sha->h;
}

static void	sha512_init(char *s, t_sha5 *sha)
{
	uint64_t	i;
	uint64_t	bit_len;

	i = -1;
	while (++i < 8)
		sha->H[i] = g_sha512_iv[i];
	sha->set = (ft_strlen(s) + 8) / 128 + 1;
	sha->n = (u_char *)malloc(128 * sha->set);
	i = -1;
	while (++i < 128 * sha->set)
		sha->n[i] = 0;
	i = -1;
	while (s[++i])
		sha->n[i] = s[i];
	sha->n[i] = 1 << 7;
	bit_len = i << 3;
	i = -1;
	while (++i < 8)
		sha->n[128 * sha->set - i - 1] = bit_len >> (i * 8);
}

void		sha512_hash(char *s)
{
	t_sha5		sha;
	uint64_t	set;

	sha512_init(s, &sha);
	set = -1;
	while (++set < sha.set)
		sha512_process(set, &sha);
	set = -1;
	while (++set < 8)
		FP("%.8lx", sha.H[set]);
	free(sha.n);
}
