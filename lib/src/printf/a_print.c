/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:38:01 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 00:21:50 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*btox(char *b)
{
	char	*res;
	char	*t1;
	char	*t2;
	int		i;

	res = ft_strnew(ft_strlen(b) / 4);
	i = 0;
	while (i < (int)ft_strlen(b) / 4)
	{
		t1 = ft_strsub(b, 4 * i, 4);
		t2 = ft_itoa_base(ft_atoi_base(t1, BINARY), HEXA, 0);
		res[i++] = t2[0];
		ft_strdel(&t1);
		ft_strdel(&t2);
	}
	return (res);
}

static void	get_hex(long double n, t_s fs, int *e, char **hex)
{
	char	*bin;
	char	*temp;

	if (fs.length == L_LENGTH)
	{
		bin = ftob(n, LONG_DOUBLE_LEN, LONG_DOUBLE_BIAS);
		temp = ft_strsub(bin, 1, 14);
		*hex = btox(bin + 15);
	}
	else if (fs.length == l_LENGTH)
	{
		bin = ftob(n, DOUBLE_LEN, DOUBLE_BIAS);
		temp = ft_strsub(bin, 1, 11);
		*hex = btox(bin + 12);
	}
	else
	{
		bin = ftob(n, FLOAT_LEN, FLOAT_BIAS);
		temp = ft_strsub(bin, 1, 8);
		*hex = btox(bin + 9);
	}
	*e = ft_atoi_base(temp, 2) - 127;
	ft_strdel(&temp);
	ft_strdel(&bin);
}

int			a_print(va_list *ap, t_s fs)
{
	long double	f;
	int			e;
	int			i;
	char		*hex;
	char		*temp;

	f = get_float_number(ap, fs);
	get_hex(f, fs, &e, &temp);
	i = 0;
	while (temp[ft_strlen(temp) - i - 1] == '0')
		i++;
	hex = ft_strsub(temp, 0, ft_strlen(temp) - i);
	is_sign(f < 0, fs);
	hex[1] ? ft_putstr("0x1.") : ft_putstr("0x1");
	ft_putstr(hex);
	fs.is_upper ? ft_putstr("P+") : ft_putstr("p+");
	ft_putnbr(e);
	return (0);
}
