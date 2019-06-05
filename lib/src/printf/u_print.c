/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:26:55 by hnam              #+#    #+#             */
/*   Updated: 2019/04/08 17:38:03 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	get_unsigned_number(va_list *ap, t_s fs)
{
	if (fs.length == l_LENGTH)
		return ((unsigned long)va_arg(*ap, unsigned long));
	else if (fs.length == ll_LENGTH)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (fs.length == h_LENGTH)
		return ((unsigned short)va_arg(*ap, unsigned int));
	else if (fs.length == hh_LENGTH)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else
		return ((unsigned int)va_arg(*ap, unsigned int));
}

static int	ret_val(uint64_t n, t_s fs)
{
	if (fs.prec > fs.width && fs.prec > ft_numlen(ABS(n), 10))
		return (fs.prec + (fs.plus || fs.space));
	else if (fs.width > fs.prec && fs.width > ft_numlen(ABS(n), 10))
		return (fs.width);
	else
	{
		if (!n && fs.dot && !fs.prec)
			return ((fs.plus || fs.space));
		return (ft_numlen(ABS(n), 10) + (fs.plus || fs.space));
	}
}

int			u_print(va_list *ap, t_s fs)
{
	uint64_t	n;
	int			len;

	n = get_unsigned_number(ap, fs);
	len = fs.width - (fs.plus || fs.space) - ((fs.dot && !fs.prec) ? -1 : 0) -
	((fs.prec > ft_numlen(ABS(n), 10)) ? fs.prec : ft_numlen(ABS(n), 10));
	if (fs.zero)
	{
		if (!fs.prec)
			ft_putnbr_width(n, fs.width - (fs.plus || fs.space), fs);
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

void		ft_putnbr_width_u(uint64_t n, int minimum_len, t_s fs)
{
	int amount;

	if (fs.plus)
		ft_putchar('+');
	else if (fs.space)
		ft_putchar(' ');
	amount = minimum_len - ft_numlen(ABS(n), 10);
	if (minimum_len != 0)
		ft_make_width(amount, '0');
	(fs.dot && !fs.prec && !n) ? 0 : ft_putnbr_u(n);
}
