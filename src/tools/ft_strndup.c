/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:14:45 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/15 15:15:21 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strndup(char **s, int c)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(*s);
	if (!(dest = ft_strnew(size + 1)))
		return (NULL);
	while ((*s)[i] != c && (*s)[i])
	{
		dest[i] = (*s)[i];
		i++;
	}
	dest[i] = '\0';
	ft_strdel(s);
	return (dest);
}
