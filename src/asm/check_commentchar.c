/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commentchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:24:42 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/29 12:07:34 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "op.h"
#include "asm.h"

void	check_commentchar(char *line)
{
	int i;

	i = 0;
	while ((line)[i])
	{
		if ((line)[i] == COMMENT_CHAR)
		{
			ft_bzero(line + i, ft_strlen(line + i));
			break ;
		}
		i++;
	}
}


static char 	*ft_trim_empty(char *tmp, char *str)
{
	tmp = ft_strnew(0);
	tmp[0] = '\0';
	ft_bzero(str, ft_strlen(str));
	str = ft_strcpy(str, tmp);
	ft_memdel((void**)&tmp);
	return (str);
}

char	*ft_trim(char *str)
{
	int i;
	int j;
	int len;
	char *tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	tmp = NULL;
	while (str[len] && (str[len] == TAB || str[len] == SPACE))
		len--;
	if (len == -1)
		return (ft_trim_empty(tmp, str));
	while (str[i] && (str[i] == TAB || str[i] == SPACE))
		i++;
	if (!(tmp = ft_strnew(len - i + 1)))
		return (NULL);
	j = 0;
	len = len - i;
	while (j < len + 1)
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	ft_bzero(str, ft_strlen(str));
	str = ft_strcpy(str, tmp);
	ft_memdel((void**)&tmp);
	return (str);
}
