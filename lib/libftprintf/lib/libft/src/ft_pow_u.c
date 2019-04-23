/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:23:40 by hnam              #+#    #+#             */
/*   Updated: 2019/04/04 01:23:41 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_pow_u(uint64_t base, int times)
{
	if (times == 0)
		return (1);
	else if (times == 1)
		return (base);
	else
		return (ft_pow_u(base, times - 1) * base);
}
