/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:13:34 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/05 11:33:23 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <unistd.h>

static int		end_of_file(char **rest, char **str, char **line)
{
	unsigned int	i;

	if (ft_strcmp(*rest, *str) == 0 && (*rest)[0] == '\0')
	{
		ft_strdel(str);
		ft_strdel(rest);
		return (0);
	}
	if (ft_strchr(*str, '\n'))
	{
		i = 0;
		while ((*str)[i] != '\n')
			i++;
		ft_strdel(rest);
		*rest = ft_strsub(*str, i + 1, ft_strlen(*str));
		*line = ft_strndup(str, '\n');
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(rest);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*str;
	static char		*rest = NULL;

	if (fd < 0 || (ret = read(fd, buf, 0)) == -1)
		return (-1);
	if (rest == NULL)
		rest = ft_strnew(0);
	str = ft_strdup(rest);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(ft_realloc(&str)))
			return (-1);
		str = ft_strcat(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (end_of_file(&rest, &str, line));
}
