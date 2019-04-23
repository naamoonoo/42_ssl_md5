/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:40:33 by hnam              #+#    #+#             */
/*   Updated: 2019/02/15 19:40:35 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (!(res = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(res, '\0', size);
	res[size] = '\0';
	return (res);
}
