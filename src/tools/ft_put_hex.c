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

	if (!(hexa = ft_uitoa_base(n, 16)))
		return ;
	ft_putstr_fd(hexa, fd);
	free(hexa);
}
