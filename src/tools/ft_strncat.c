/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:54:10 by jthillar          #+#    #+#             */
/*   Updated: 2017/12/05 10:55:16 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t n_dest;

	i = 0;
	n_dest = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[n_dest + i] = (char)src[i];
		i++;
	}
	dest[n_dest + i] = '\0';
	return (dest);
}
