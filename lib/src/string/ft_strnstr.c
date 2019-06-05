/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:27:25 by hnam              #+#    #+#             */
/*   Updated: 2019/02/14 08:27:26 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = -1;
	if (!s1[0])
		return (NULL);
	while (s1[++i] && i + ft_strlen(s2) <= len)
		if (s1[i] == s2[0])
			if (ft_strncmp((char *)&s1[i], s2, ft_strlen(s2)) == 0)
				return ((char *)&s1[i]);
	return (s2[0] != '\0' ? NULL : (char *)s1);
}
