/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:12:31 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 13:42:21 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

void		ft_put_hex_fd(unsigned int n, int fd, int len)
{
	char	*hexa;
	int		size;

	if (len <= 2)
	{
		if (!(hexa = ft_uctoa_base(n, 16)))
			return ;
	}
	else if (len <= 4)
	{
		if (!(hexa = ft_ustoa_base(n, 16)))
		   return ;
	}
	else
	{
		if (!(hexa = ft_uitoa_base(n, 16)))
		   return ;
	}
	size = ft_strlen(hexa);
	while (size < len)
	{
		ft_putstr_fd("0", fd);
		len--;
	}
	ft_putstr_fd(hexa, fd);
	free(hexa);
}
