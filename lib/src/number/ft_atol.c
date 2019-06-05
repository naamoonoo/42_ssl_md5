/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:54:02 by hnam              #+#    #+#             */
/*   Updated: 2019/06/01 22:57:03 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	ans;
	int		is_neg;

	i = 0;
	ans = 0;
	is_neg = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\f' ||
		str[i] == '\v' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		is_neg = str[i++] == '-' ? 1 : 0;
	while (str[i] >= '0' && str[i] <= '9')
		ans = ans * 10 + (str[i++] - '0');
	return (is_neg ? ans * -1 : ans);
}
