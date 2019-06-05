/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:31:47 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 09:47:34 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double			get_float_number(va_list *ap, t_s fs)
{
	if (fs.length == L_LENGTH)
		return ((long double)va_arg(*ap, long double));
	if (fs.length == l_LENGTH)
		return ((double)va_arg(*ap, double));
	else
		return ((float)va_arg(*ap, double));
}

int					f_print(va_list *ap, t_s fs)
{
	long double	f;
	int			len;

	f = get_float_number(ap, fs);
	if (!fs.prec)
		fs.prec = fs.dot ? 0 : 6;
	fs.dot = (fs.prec || fs.hash);
	len = ft_numlen(ABS((int)f), 10) +
		fs.dot + fs.prec + is_sign(f < 0, fs);
	if (!fs.minus && fs.zero)
	{
		sign_handler(f < 0, fs);
		ft_make_width(fs.width - len, '0');
	}
	(!fs.minus && !fs.zero) ? ft_make_width(fs.width - len, ' ') : 0;
	ft_put_float(f, fs);
	fs.minus ? ft_make_width(fs.width - len, ' ') : 0;
	return (get_big(len, fs.width));
}

static long double	handled_number(long double f, int *e_num)
{
	if (*e_num == -4242)
	{
		if (ABS((int)f) == 0)
		{
			*e_num = 0;
			while (ABS(f) > 0.0 && ABS(f) < 1.0)
			{
				f *= 10.0;
				*e_num -= 1;
			}
		}
		else if (ABS((int)f) > 10)
		{
			*e_num = ft_numlen(ABS((int)f), 10) - 1;
			while (ABS(f) > 10.0)
				f /= 10.0;
		}
		else
			*e_num = 0;
	}
	else
		*e_num = -4242;
	return (f);
}

int					e_print(va_list *ap, t_s fs)
{
	long double	f;
	int			len;
	int			e_num;

	e_num = -4242;
	f = handled_number(get_float_number(ap, fs), &e_num);
	if (!fs.prec)
		fs.prec = fs.dot ? 0 : 6;
	fs.dot = (fs.prec || fs.hash);
	len = ft_numlen(ABS((int)f), 10) + 4 + (e_num < 0 ? 1 : 0) +
		fs.dot + fs.prec + is_sign(f < 0, fs);
	if (!fs.minus && fs.zero)
	{
		sign_handler(f < 0, fs);
		ft_make_width(fs.width - len + 1, '0');
	}
	(!fs.minus && !fs.zero) ? ft_make_width(fs.width - len + 1, ' ') : 0;
	ft_put_float(f, fs);
	ft_put_expo(e_num, fs);
	fs.minus ? ft_make_width(fs.width - len, ' ') : 0;
	return (get_big(len, fs.width));
}

int					g_print(va_list *ap, t_s fs)
{
	long double	f;
	int			len;
	int			e_num;
	int			is_e;

	f = get_float_number(ap, fs);
	is_e = (get_enum(f) < -4);
	e_num = is_e ? -4242 : 0;
	f = is_e ? handled_number(f, &e_num) : f;
	if (!fs.prec)
		fs.prec = fs.dot ? 0 : 6;
	fs.dot = (fs.prec || fs.hash);
	len = ft_numlen(ABS((int)f), 10) + (is_e ? 5 : 0) +
		fs.dot + fs.prec + is_sign(f < 0, fs);
	if (!fs.minus && fs.zero)
	{
		sign_handler(f < 0, fs);
		ft_make_width(fs.width - len + (is_e ? 1 : 0), '0');
	}
	if (!fs.minus && !fs.zero)
		ft_make_width(fs.width - len + (is_e ? 1 : 0), ' ');
	ft_put_float(f, fs);
	is_e ? ft_put_expo(e_num, fs) : 0;
	fs.minus ? ft_make_width(fs.width - len, ' ') : 0;
	return (get_big(len, fs.width));
}
