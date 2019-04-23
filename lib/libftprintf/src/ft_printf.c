/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:32:25 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:32:37 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *s, ...)
{
	va_list ap;
	int		res;

	va_start(ap, s);
	res = 0;
	while (*s)
	{
		if (*s == '%')
			ft_formatting(&s, &ap, &res);
		else if (*s == '{')
			ft_coloring(&s, &res);
		else
		{
			ft_putchar(*s++);
			res++;
		}
	}
	va_end(ap);
	return (res);
}

int	ft_printf_fd(int fd, ...)
{
	va_list ap;
	int		res;
	char	*s;

	va_start(ap, fd);
	res = 0;
	while (get_next_line(fd, &s) > 0)
	{
		while (*s)
		{
			if (*s == '%')
				ft_formatting(&s, &ap, &res);
			else if (*s == '{')
				ft_coloring(&s, &res);
			else
			{
				ft_putchar(*s++);
				res++;
			}
		}
		ft_putchar('\n');
	}
	va_end(ap);
	return (res);
}
