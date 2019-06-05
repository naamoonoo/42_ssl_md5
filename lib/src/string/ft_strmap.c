/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:41:25 by hnam              #+#    #+#             */
/*   Updated: 2019/02/15 19:41:26 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	i = -1;
	if (s)
	{
		if (!(res = ft_strnew(ft_strlen(s))))
			return (NULL);
		else
			while (s[++i])
				res[i] = f(s[i]);
		return (res);
	}
	return (NULL);
}
