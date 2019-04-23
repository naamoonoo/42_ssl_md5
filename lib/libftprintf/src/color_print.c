/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:26:33 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:32:09 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_table	g_t[] =
{
	{"{red}", "\033[0;31m"},
	{"{green}", "\033[0;32m"},
	{"{yellow}", "\033[0;33m"},
	{"{blue}", "\033[0;34m"},
	{"{magenta}", "\033[0;35m"},
	{"{cyan}", "\033[0;36m"},
	{"{eoc}", "\033[0m"},
	{NULL, NULL},
};

void	ft_coloring(char **s, int *res)
{
	int		i;
	char	color[MAX_INPUT];

	i = 0;
	while (**s != '}' && **s != '\0')
	{
		color[i++] = **s;
		*s += 1;
		if (**s == '}')
			color[i++] = '}';
	}
	color[i] = '\0';
	i = -1;
	while (ft_strlen(color) < 11 && g_t[++i].color)
	{
		if (ft_strcmp(color, g_t[i].color) == 0)
		{
			ft_putstr(g_t[i].code);
			*s += 1;
			return ;
		}
	}
	ft_printf("\033[0m%s", color);
	*res += ft_strlen(color);
	**s != '\0' ? *s += 1 : 0;
}
