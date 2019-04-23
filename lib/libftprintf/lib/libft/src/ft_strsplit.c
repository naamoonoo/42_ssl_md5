/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:42:27 by hnam              #+#    #+#             */
/*   Updated: 2019/02/15 19:42:28 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**make_array(char const *s, char c)
{
	unsigned int	i;
	int				len;
	char			**res;

	i = 0;
	len = s[0] == c ? 0 : 1;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			len++;
		i++;
	}
	if (!(res = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	int				len;
	int				start;
	char			**res;

	if (!s)
		return (NULL);
	if (!(res = make_array(s, c)))
		return (NULL);
	start = 0;
	i = 0;
	len = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		if (s[i] != c && s[i + 1] == c)
			res[len++] = ft_strsub(s, start, i - start + 1);
		if (i + 2 == ft_strlen(s) && s[i + 1] != c)
			res[len++] = ft_strsub(s, start, i - start + 2);
		i++;
	}
	res[len] = ((void *)0);
	return (res);
}
