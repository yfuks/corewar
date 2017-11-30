/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:07:25 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/30 10:08:11 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static char	*ft_trim_empty(char *tmp, char *str)
{
	tmp = ft_strnew(0);
	tmp[0] = '\0';
	ft_bzero(str, ft_strlen(str));
	str = ft_strcpy(str, tmp);
	ft_memdel((void**)&tmp);
	return (str);
}

static char	*ft_trim_copy(char *str, char *tmp, int len, int i)
{
	int j;

	j = 0;
	len = len - i;
	while (j < len + 1)
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	return (tmp);
}

char		*ft_trim(char *str)
{
	int		i;
	int		len;
	char	*tmp;

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
	tmp = ft_trim_copy(str, tmp, len, i);
	ft_bzero(str, ft_strlen(str));
	str = ft_strcpy(str, tmp);
	ft_memdel((void**)&tmp);
	return (str);
}
