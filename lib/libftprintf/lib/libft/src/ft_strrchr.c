/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:58:07 by hnam              #+#    #+#             */
/*   Updated: 2019/02/13 23:58:08 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	while (len != 0 && s[--len])
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	return (NULL);
}
