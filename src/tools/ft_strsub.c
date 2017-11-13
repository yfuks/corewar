/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:29:25 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/13 15:31:21 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(str = ft_strnew(len)) || !s)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
