/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 07:36:27 by hnam              #+#    #+#             */
/*   Updated: 2019/02/21 07:36:29 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *res;

	if (!(res = (char *)malloc(size * sizeof(char))))
		return (NULL);
	ft_memset(res, 0, size);
	return (res);
}
