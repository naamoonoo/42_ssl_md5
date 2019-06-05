/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:41:36 by hnam              #+#    #+#             */
/*   Updated: 2019/02/15 19:41:37 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s)
	{
		if (!(res = ft_strnew(ft_strlen(s))))
			return (NULL);
		else
		{
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
		}
		return (res);
	}
	return (NULL);
}
