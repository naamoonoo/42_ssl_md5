/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:23:02 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:23:12 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*make_base_set(char *base, int str_base)
{
	int		i;
	char	*base_set;

	i = -1;
	base_set = "0123456789abcdef";
	if (!(base = (char *)malloc(sizeof(char) * (str_base + 1))))
		return (NULL);
	while (++i < str_base)
		base[i] = base_set[i];
	base[i] = '\0';
	return (base);
}

char			*ft_itoa_base_u(uint64_t n, int str_base, int len)
{
	char		*res;
	char		*base_set;
	int			i;
	uint64_t	dv;
	int			num_len;

	i = 0;
	num_len = ft_numlen(n, (uint64_t)str_base);
	dv = ft_pow_u(str_base, num_len - 1);
	base_set = NULL;
	if (!(res = (char *)malloc((num_len + len + 1) * sizeof(char))))
		return (NULL);
	base_set = make_base_set(base_set, str_base);
	if (len > num_len)
		while (i < len - num_len)
			res[i++] = '0';
	while (num_len-- > 0)
	{
		res[i++] = base_set[n / dv];
		n -= (n / dv) * dv;
		dv /= str_base;
	}
	res[i] = '\0';
	ft_strdel(&base_set);
	return (res);
}
