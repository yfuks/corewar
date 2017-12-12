/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <alansiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:39:16 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/29 19:23:54 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*buffer;

	if (!(buffer = malloc(size)))
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}
