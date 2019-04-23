/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxb_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:19:31 by hnam              #+#    #+#             */
/*   Updated: 2019/04/03 21:35:49 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ret_val(uint64_t d, t_s fs, int base)
{
	int len;

	len = ft_numlen(d, base);
	if (fs.prec > fs.width && fs.prec > len + fs.hash)
		return (fs.prec + (base == HEXA ? fs.hash : 0));
	else if (fs.width > fs.prec && fs.width > len + fs.hash)
		return (fs.width);
	else
	{
		if (d == 0)
		{
			if (fs.dot && !fs.prec)
				return ((base == OCTAL && fs.hash) ? 1 : 0);
			return (len);
		}
		return (len + fs.hash);
	}
}

static void	oxb_print_helper(t_s fs, char *temp, char *hash)
{
	if (fs.minus)
	{
		ft_putstr(fs.hash ? hash : 0);
		fs.is_upper ? ft_putstr_upper(temp) : ft_putstr(temp);
		ft_make_width(fs.width - fs.hash - (int)ft_strlen(temp), ' ');
	}
	else if (fs.zero)
	{
		if (fs.prec)
			ft_make_width(fs.width - fs.hash - (int)ft_strlen(temp), ' ');
		ft_putstr(fs.hash ? hash : 0);
		if (!fs.prec)
			ft_make_width(fs.width - fs.hash - (int)ft_strlen(temp), '0');
		fs.is_upper ? ft_putstr_upper(temp) : ft_putstr(temp);
	}
	else
	{
		ft_make_width(fs.width - fs.hash - (int)ft_strlen(temp), ' ');
		ft_putstr(fs.hash ? hash : 0);
		fs.is_upper ? ft_putstr_upper(temp) : ft_putstr(temp);
	}
}

int			o_print(va_list *ap, t_s fs)
{
	u_int64_t	d;
	int			len;
	char		*temp;
	char		*hash;

	d = get_unsigned_number(ap, fs);
	if (d == 0 && fs.dot && fs.prec == 0)
		temp = fs.hash ? "0" : "";
	else
		temp = ft_itoa_base_u(d, OCTAL, get_big(fs.prec, ft_numlen(d, OCTAL)));
	len = ret_val(d, fs, OCTAL);
	fs.hash = (fs.hash && d != 0 && (ft_numlen(d, OCTAL) >= fs.prec))
		? fs.hash : 0;
	hash = "0";
	if (len == fs.width)
		oxb_print_helper(fs, temp, hash);
	else
	{
		ft_putstr(fs.hash ? hash : 0);
		ft_putstr(temp);
	}
	(d == 0 && fs.dot && fs.prec == 0) ? 0 : ft_strdel(&temp);
	return (len);
}

int			x_print(va_list *ap, t_s fs)
{
	u_int64_t	d;
	int			len;
	char		*temp;
	char		*hash;

	d = get_unsigned_number(ap, fs);
	if (d == 0 && fs.dot && fs.prec == 0)
		temp = "";
	else
		temp = ft_itoa_base_u(d, HEXA, get_big(fs.prec, ft_numlen(d, HEXA)));
	fs.hash = (fs.hash && d != 0) ? 2 : 0;
	len = ret_val(d, fs, HEXA);
	hash = fs.is_upper ? "0X" : "0x";
	if (len == fs.width)
		oxb_print_helper(fs, temp, hash);
	else
	{
		ft_putstr(fs.hash ? hash : 0);
		fs.is_upper ? ft_putstr_upper(temp) : ft_putstr(temp);
	}
	(d == 0 && fs.dot && fs.prec == 0) ? 0 : ft_strdel(&temp);
	return (len);
}

int			b_print(va_list *ap, t_s fs)
{
	u_int64_t	d;
	int			len;
	char		*temp;
	char		*hash;

	d = get_unsigned_number(ap, fs);
	if (d == 0 && fs.dot && fs.prec == 0)
		temp = "";
	else
		temp = ft_itoa_base_u(d, BINARY,
			get_big(fs.prec, ft_numlen(d, BINARY)));
	fs.hash = (fs.hash && d != 0) ? 2 : 0;
	len = ret_val(d, fs, BINARY);
	hash = "0b";
	if (len == fs.width)
		oxb_print_helper(fs, temp, hash);
	else
	{
		ft_putstr(fs.hash ? hash : 0);
		fs.is_upper ? ft_putstr_upper(temp) : ft_putstr(temp);
	}
	(d == 0 && fs.dot && fs.prec == 0) ? 0 : ft_strdel(&temp);
	return (len);
}
