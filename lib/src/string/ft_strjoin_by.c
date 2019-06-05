/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_by.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:42:09 by hnam              #+#    #+#             */
/*   Updated: 2019/04/16 17:21:11 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_by(char const *s1, char const *s2, char *c)
{
	char *res;

	if (s1 && s2 && c)
	{
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(c))))
			return (NULL);
		res = ft_strcpy(res, s1);
		res = ft_strcat(res, c);
		res = ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
