/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:42:32 by hnam              #+#    #+#             */
/*   Updated: 2019/05/13 12:41:39 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	minus_handling(int *n, char *res, int *len, int *i)
{
	*n = ABS(*n);
	res[*i] = '-';
	*i = *i + 1;
	*len = *len + 1;
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;
	int		dv;

	i = 0;
	len = ft_numlen(ABS(n), 10);
	dv = ft_pow(10, len - 1);
	if (!(res = (char *)malloc((n < 0 ? len + 2 : len + 1) * sizeof(char))))
		return (NULL);
	if (n == MAX_INT)
		return (ft_strcpy(res, "-2147483648"));
	if (n < 0)
		minus_handling(&n, res, &len, &i);
	while (i < len)
	{
		res[i++] = n / dv + '0';
		n -= (n / dv) * dv;
		dv /= 10;
	}
	res[i] = '\0';
	return (res);
}
