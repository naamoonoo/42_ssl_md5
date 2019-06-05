/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:23:26 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:23:28 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(uint64_t n, uint64_t base)
{
	if (n < base)
		return (1);
	else
		return (ft_numlen(n % base, base)
			+ ft_numlen(n / base, base));
}
