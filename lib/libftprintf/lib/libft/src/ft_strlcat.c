/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:57:12 by hnam              #+#    #+#             */
/*   Updated: 2019/02/13 23:57:14 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t limit;
	size_t ans;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	ans = i + j;
	if (i >= dstsize)
		return (dstsize + j);
	limit = dstsize - i - 1 > j ? j : dstsize - i - 1;
	j = 0;
	while (j < limit)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ans);
}
