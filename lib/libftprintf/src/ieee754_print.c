/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieee754_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:32:51 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:32:58 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*normalized_float_number(long double n, int size)
{
	char	*res;
	char	*temp;
	int		i;
	float	dv;

	i = 0;
	dv = 1.0 / 2.0;
	res = ft_strnew(size);
	res[i++] = n < 0 ? '1' : '0';
	n = ABS(n);
	temp = ft_itoa_base_u((uint64_t)n, 2, 0);
	ft_strcat(res, temp);
	i += ft_strlen(temp);
	ft_strdel(&temp);
	res[i++] = '.';
	n -= (uint64_t)n;
	while (i <= size && n > 0)
	{
		res[i++] = (n >= dv ? '1' : '0');
		n -= (n >= dv ? dv : 0);
		dv /= 2.0;
	}
	return (res);
}

char		*ftob(long double n, int size, int bias)
{
	char	*res;
	char	*nf;
	char	*temp;
	int		exponent;
	int		idx;

	nf = normalized_float_number(n, size);
	res = ft_strnew(size);
	res[0] = nf[0];
	exponent = ft_strchr_idx(nf, '.') - 2;
	temp = ft_itoa_base_u(exponent + bias, 2, 0);
	ft_strcat(res, temp);
	ft_strdel(&temp);
	ft_strcat(res, nf + 2);
	ft_strdel(&nf);
	idx = ft_strchr_idx(res, '.');
	ft_memmove(res + idx, res + idx + 1, ft_strlen(res) - idx);
	idx = ft_strlen(res);
	if (idx < size)
		while (idx < size)
			res[idx++] = '0';
	else
		while (idx >= size)
			res[idx--] = '\0';
	return (res);
}

int			ieee754_print(va_list *ap, t_s fs)
{
	long double	f;
	char		*bin;
	int			len;

	f = get_float_number(ap, fs);
	if (fs.length == L_LENGTH)
		bin = ftob(f, LONG_DOUBLE_LEN, LONG_DOUBLE_BIAS);
	else if (fs.length == l_LENGTH)
		bin = ftob(f, DOUBLE_LEN, DOUBLE_BIAS);
	else
		bin = ftob(f, FLOAT_LEN, FLOAT_BIAS);
	len = ft_strlen(bin);
	!fs.minus ? ft_make_width(fs.width - len, ' ') : 0;
	ft_putstr(bin);
	fs.minus ? ft_make_width(fs.width - len, ' ') : 0;
	ft_strdel(&bin);
	return (len);
}
