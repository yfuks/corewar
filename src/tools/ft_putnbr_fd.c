/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:21:44 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 14:24:42 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tools.h"

void		ft_putnbr_fd(int n, int fd)
{
	char		*str;

	if (!(str = ft_itoa(n)))
		return ;
	ft_putstr_fd(str, fd);
	free(str);
}
