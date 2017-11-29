/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:29:25 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/29 15:34:48 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	end;

	if (s == NULL)
		return (NULL);
	i = 0;
	end = start + len;
	dest = ft_strnew(sizeof(char) * (len));
	if (dest == NULL)
		return (NULL);
	while (start < end)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strsub2(char *str, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	end;

	if (str == NULL)
		return (NULL);
	i = 0;
	end = start + len;
	dest = ft_strnew(sizeof(char) * (len));
	if (dest == NULL)
		return (NULL);
	while (start < end)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	ft_bzero(str, ft_strlen(str));
	str = ft_strcpy(str, dest);
	ft_memdel((void**)&dest);
	return (str);
}
