/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:25:08 by hnam              #+#    #+#             */
/*   Updated: 2019/04/08 16:39:15 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dt	g_dt[] =
{
	{'c', c_print},
	{'s', s_print},
	{'p', p_print},
	{'d', di_print},
	{'i', di_print},
	{'o', o_print},
	{'u', u_print},
	{'x', x_print},
	{'X', x_print},
	{'f', f_print},
	{'b', b_print},
	{'e', e_print},
	{'E', e_print},
	{'g', g_print},
	{'G', g_print},
	{'%', pct_print},
	{'a', a_print},
	{'A', a_print},
	{'B', ieee754_print},
	{'n', length_print},
	{0, NULL}
};

void	ft_formatting(char **s, va_list *ap, int *res)
{
	t_s		fs;
	int		format;
	int		len;

	len = 0;
	flag_setting(&fs);
	format = get_format(s, &format, &fs);
	if (fs.w_star || fs.p_star)
		star_handler(ap, &fs);
	if (g_dt[format].specifier)
		len = g_dt[format].function(ap, fs);
	*res += len > 0 ? len : 0;
	*s += 1;
}

void	flag_setting(t_s *fs)
{
	fs->plus = 0;
	fs->minus = 0;
	fs->hash = 0;
	fs->space = 0;
	fs->zero = 0;
	fs->width = 0;
	fs->dot = 0;
	fs->prec = 0;
	fs->length = 0;
	fs->w_star = 0;
	fs->p_star = 0;
}

void	get_flag(char c, t_s *fs)
{
	if (c == '+')
		fs->plus = 1;
	else if (c == '-')
		fs->minus = 1;
	else if (c == '#')
		fs->hash = 1;
	else if (c == ' ')
		fs->space = fs->plus ? 0 : 1;
	else if (c == '.')
		fs->dot = 1;
	else if (c == '*' && fs->dot)
		fs->p_star = 1;
	else if (c == '*' && !fs->dot)
		fs->w_star = 1;
	else if (fs->dot && c >= '0' && c <= '9')
		fs->prec = (fs->prec * 10) + c - '0';
	else if (c >= '1' && c <= '9')
		fs->width = (fs->width * 10) + c - '0';
	else if (fs->width && c == '0')
		fs->width = (fs->width * 10) + c - '0';
	else if (!fs->width && c == '0')
		fs->zero = fs->minus ? 0 : 1;
	fs->zero = (fs->zero && fs->minus) ? 0 : fs->zero;
	fs->space = (fs->plus && fs->space) ? 0 : fs->space;
}

int		get_length(char **s, t_s *fs)
{
	if (**s == 'h')
	{
		if (fs->length == h_LENGTH)
			return ((fs->length ^ h_LENGTH) | hh_LENGTH);
		else
			return (fs->length | h_LENGTH);
	}
	else if (**s == 'l')
	{
		if (fs->length == l_LENGTH)
			return ((fs->length ^ l_LENGTH) | ll_LENGTH);
		else
			return (fs->length | l_LENGTH);
	}
	else if (**s == 'L')
		return (fs->length | L_LENGTH);
	return (0);
}

int		get_format(char **s, int *flag, t_s *fs)
{
	int i;

	*s += 1;
	i = -1;
	if (ft_strchr(FLAG_SPECIFIER, **s))
	{
		get_flag(**s, fs);
		return (get_format(s, flag, fs));
	}
	else if (ft_strchr(LENGTH_SPECIFIER, **s))
	{
		fs->length = get_length(s, fs);
		return (get_format(s, flag, fs));
	}
	else if (ft_strchr(SPECIFIER, **s))
		while (++i < (int)KIND_OF_SPECIFIER)
			if (g_dt[i].specifier == **s)
			{
				fs->is_upper = ft_strchr("XEGA", **s) ? 1 : 0;
				fs->is_g = ft_strchr("gG", **s) ? 1 : 0;
				return (i);
			}
	return (0);
}
