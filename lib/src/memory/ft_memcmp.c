/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:54:19 by hnam              #+#    #+#             */
/*   Updated: 2019/02/14 12:54:20 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = -1;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (++i < n)
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
	return (0);
}
