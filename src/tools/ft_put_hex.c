/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:12:31 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 16:14:33 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdlib.h>

void		ft_put_hex_fd(unsigned int n, int fd)
{
	char	*hexa;
	int		len;

	if (!(hexa = ft_uitoa_base(n, 16)))
		return ;
	if ((len = ft_strlen(hexa)) > 2)
	{
		hexa[0] = hexa[len];
		hexa[1] = hexa[len -1];
		hexa[2] = 0;
	}
	else if (ft_strlen(hexa) == 1)
		ft_putstr_fd("0", fd);
	ft_putstr_fd(hexa, fd);
	free(hexa);
}
