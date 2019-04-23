/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andY <andY@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:42:32 by hnam              #+#    #+#             */
/*   Updated: 2019/03/31 01:01:20 by andY             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int64_t n)
{
	char	*res;
	int		len;
	int		i;
	int		dv;

	i = 0;
	len = ft_numlen(ABS(n), 10);
	dv = ft_pow(10, len);
	if (!(res = (char *)malloc((n < 0 ? len + 2 : len + 1) * sizeof(char))))
		return (NULL);
	if (n == MAX_INT)
		return (ft_strcpy(res, "-2147483648"));
	if (n < 0)
		itoa_minus_hande(&n, res, &len, &i);
	while (i < len)
	{
		res[i++] = n / dv + '0';
		n -= (n / dv) * dv;
		dv /= 10;
	}
	res[i] = '\0';
	return (res);
}
