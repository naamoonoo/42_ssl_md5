/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:07:54 by hnam              #+#    #+#             */
/*   Updated: 2019/06/05 12:07:54 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_file(int fd, char **file)
{
	char	*buf;
	char	*str;
	char	*tmp;
	int		gnl;

	buf = NULL;
	str = NULL;
	while ((gnl = get_next_line(fd, &buf)) > 0)
	{
		if (str)
		{
			tmp = ft_strjoin_by(str, buf, "\n");
			free(str);
			str = ft_strdup(tmp);
			free(tmp);
		}
		else
			str = ft_strdup(buf);
		free(buf);
	}
	if (gnl < 0)
		return (-1);
	*file = strdup(str);
	free(str);
	return (0);
}
