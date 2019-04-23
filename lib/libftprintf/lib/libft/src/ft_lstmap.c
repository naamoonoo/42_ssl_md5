/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 10:41:30 by hnam              #+#    #+#             */
/*   Updated: 2019/03/20 02:17:25 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	res = temp;
	while (lst)
	{
		if (lst->next)
		{
			lst = lst->next;
			temp->next = f(lst);
			temp = temp->next;
		}
		else
			break ;
	}
	temp->next = (NULL);
	return (res);
}
