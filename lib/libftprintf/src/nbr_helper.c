/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:33:07 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 09:47:49 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_sign(int is_minus, t_s fs)
{
	return (is_minus || fs.plus || fs.space);
}

void	sign_handler(int is_minus, t_s fs)
{
	if (is_minus)
		return (ft_putchar('-'));
	else if (fs.plus)
		return (ft_putchar('+'));
	else if (!fs.plus && fs.space)
		return (ft_putchar(' '));
}

void	ft_putnbr_width(int64_t n, int minimum_len, t_s fs)
{
	int amount;

	sign_handler(n < 0, fs);
	n *= n < 0 ? -1 : 1;
	amount = minimum_len - ft_numlen(ABS(n), 10);
	if (minimum_len != 0)
		ft_make_width(amount, '0');
	(fs.dot && !fs.prec && !n) ? 0 : ft_putnbr(n);
}

void	ft_put_float(long double n, t_s fs)
{
	int t;

	!(!fs.minus && fs.zero) ? sign_handler(n < 0, fs) : 0;
	n = ABS(n);
	n += (fs.prec <= 15) ? 0.0000000000000001 : 0;
	if (fs.prec == 0)
		n += (((int)(n * 10) % 10) < 5) ? 0 : 1;
	ft_putnbr((int)n);
	if (fs.dot)
		ft_putchar('.');
	while (fs.prec-- > 0)
	{
		n = 10 * n;
		if (fs.prec == 0)
			n += (int)(n * 10) % 10 < 5 ? 0 : 1;
		t = (int)n;
		n -= t;
		t %= 10;
		ft_putchar(t + '0');
	}
}

void	ft_put_expo(int e_num, t_s fs)
{
	if (e_num == -42424242)
		return ;
	ft_putchar(fs.is_upper ? 'E' : 'e');
	fs.plus = 1;
	fs.space = 0;
	ft_putnbr_width(e_num, 2, fs);
}
