/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:05:39 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/29 14:55:01 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(s);
	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = (char)s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
