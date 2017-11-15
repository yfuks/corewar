/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:19:55 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/13 14:44:29 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"tools.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *mem;

	mem = (char*)malloc(sizeof(char) * (size + 1));
	if (mem != NULL)
		ft_bzero(mem, size + 1);
	else
		mem = NULL;
	return (mem);
}
