/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:19:01 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:32:46 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_width(int len, char c)
{
	while (len > 0 && len-- != 0)
		ft_putchar(c);
}

void	ft_putstr_upper(char *s)
{
	int i;

	i = -1;
	if (s)
		while (s[++i])
			ft_putchar(ft_toupper(s[i]));
}

void	star_handler(va_list *ap, t_s *fs)
{
	if (fs->w_star)
		fs->width = va_arg(*ap, int);
	if (fs->p_star)
		fs->prec = va_arg(*ap, int);
}

int		get_enum(long double f)
{
	int e_num;

	e_num = 0;
	while (ABS(f) > 0.0 && ABS(f) < 1.0)
	{
		f *= 10.0;
		e_num -= 1;
	}
	return (e_num);
}
