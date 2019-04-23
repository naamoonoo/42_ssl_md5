/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:24:41 by hnam              #+#    #+#             */
/*   Updated: 2019/04/08 16:39:24 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_print(va_list *ap, t_s fs)
{
	char	c;
	int		len;
	char	*res;

	c = (char)va_arg(*ap, int);
	len = fs.width - 1;
	res = ft_memalloc(len + 1);
	if (fs.minus)
	{
		ft_putchar(c);
		ft_make_width(len, ' ');
	}
	else
	{
		ft_make_width(len, ' ');
		ft_putchar(c);
	}
	return (len > 0 ? len + 1 : 1);
}

int	s_print(va_list *ap, t_s fs)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(null)";
	if (fs.dot && !fs.prec)
		return (0);
	if (fs.dot && fs.prec && (int)ft_strlen(s) > fs.prec)
		s = ft_strsub(s, 0, fs.prec);
	len = fs.width - ft_strlen(s);
	!fs.minus ? ft_make_width(len, ' ') : 0;
	ft_putstr(s);
	fs.minus ? ft_make_width(len, ' ') : 0;
	(fs.dot && fs.prec && ((int)ft_strlen(s) > fs.prec)) ? ft_strdel(&s) : 0;
	len = get_big(fs.width, (int)ft_strlen(s));
	return (len);
}

int	p_print(va_list *ap, t_s fs)
{
	intptr_t	ptr;
	char		*temp;
	int			len;

	ptr = va_arg(*ap, intptr_t);
	if (!ptr)
		temp = "0";
	else
		temp = ft_itoa_base(ptr, HEXA, 9);
	len = fs.width - ft_strlen(temp) - 2;
	!fs.minus ? ft_make_width(len, ' ') : 0;
	ft_putstr("0x");
	ft_putstr(temp);
	fs.minus ? ft_make_width(len, ' ') : 0;
	if ((len = get_big(fs.width, ft_strlen(temp))) != fs.width)
		len += 2;
	ptr ? ft_strdel(&temp) : 0;
	return (len);
}

int	pct_print(t_s fs)
{
	int		len;

	len = fs.width - 1;
	if (fs.minus)
	{
		ft_putchar('%');
		ft_make_width(len, ' ');
	}
	else
	{
		ft_make_width(len, fs.zero ? '0' : ' ');
		ft_putchar('%');
	}
	return (len > 0 ? len + 1 : 1);
}

int	length_print(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		return (0);
	ft_putnbr_u((uint64_t)ft_strlen(s));
	return ((uint64_t)ft_strlen(s));
}
