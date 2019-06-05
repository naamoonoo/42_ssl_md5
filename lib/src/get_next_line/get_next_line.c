/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:16:51 by hnam              #+#    #+#             */
/*   Updated: 2019/06/02 19:28:34 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_concat(char **str, char *buf, int r)
{
	char *temp;

	buf[r] = '\0';
	temp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = temp;
}

static void	first_setting(char **str)
{
	if (!*str)
		*str = ft_strnew(1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD] = { 0 };
	char		buf[BUFF_SIZE + 1];
	int			r;
	int			i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, str[fd], 0) < 0))
		return (-1);
	first_setting(&str[fd]);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0 || *str[fd])
	{
		ft_concat(&str[fd], buf, r);
		if ((i = ft_strchr_idx(str[fd], '\n')) >= 0)
		{
			*line = ft_strsub(str[fd], 0, i);
			ft_memmove(str[fd], &str[fd][i + 1], ft_strlen(str[fd]) - i);
			return (1);
		}
		if (r != BUFF_SIZE)
		{
			*line = ft_strdup(str[fd]);
			ft_strdel(&str[fd]);
			return (1);
		}
	}
	return (r < 0 ? -1 : 0);
}
