/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:26:15 by hnam              #+#    #+#             */
/*   Updated: 2019/04/02 00:26:27 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		get_number(va_list *ap, t_s fs)
{
	if (fs.length == l_LENGTH)
		return ((long)va_arg(*ap, long));
	else if (fs.length == ll_LENGTH)
		return ((long long)va_arg(*ap, long long));
	else if (fs.length == h_LENGTH)
		return ((short)va_arg(*ap, int));
	else if (fs.length == hh_LENGTH)
		return ((signed char)va_arg(*ap, int));
	else
		return ((int)va_arg(*ap, int));
}

static int	ret_val(int64_t n, t_s fs)
{
	if (fs.prec > fs.width && fs.prec > ft_numlen(ABS(n), 10))
		return (fs.prec + is_sign(n < 0, fs));
	else if (fs.width > fs.prec && fs.width > ft_numlen(ABS(n), 10))
		return (fs.width);
	else
	{
		if (!n && fs.dot && !fs.prec)
			return (is_sign(n < 0, fs));
		return (ft_numlen(ABS(n), 10) + is_sign(n < 0, fs));
	}
}

int			di_print(va_list *ap, t_s fs)
{
	int64_t n;
	int		len;

	n = get_number(ap, fs);
	len = fs.width - is_sign(n < 0, fs) - ((fs.dot && !fs.prec) ? -1 : 0) -
	((fs.prec > ft_numlen(ABS(n), 10)) ? fs.prec : ft_numlen(ABS(n), 10));
	if (fs.zero)
	{
		if (!fs.prec)
			ft_putnbr_width(n, fs.width - is_sign(n < 0, fs), fs);
		else
		{
			ft_make_width(len, ' ');
			ft_putnbr_width(n, fs.prec, fs);
		}
	}
	else
	{
		fs.minus ? ft_putnbr_width(n, fs.prec, fs) : 0;
		ft_make_width(len, ' ');
		!fs.minus ? ft_putnbr_width(n, fs.prec, fs) : 0;
	}
	return (ret_val(n, fs));
}
