/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 00:01:04 by hnam              #+#    #+#             */
/*   Updated: 2019/03/01 00:01:06 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hidenp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s2[++j])
	{
		if (s1[i] == s2[j])
			i++;
	}
	return (ft_strlen(s1) == (unsigned)i);
}