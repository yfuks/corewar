/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uctoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:49:01 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/20 16:49:05 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			len_number(unsigned char nb, int base)
{
	int				len_nb;

	len_nb = 0;
	if (nb <= 0)
	{
		if (base == 10 || nb == 0)
			len_nb += 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		len_nb++;
		nb = nb / base;
	}
	return (len_nb);
}

char				*ft_uctoa_base(unsigned char nb, int base)
{
	int				size;
	char			*ret;

	size = len_number(nb, base);
	if (!(ret = (char*)malloc(sizeof(size))))
		return (0);
	ret[size] = '\0';
	size -= 1;
	if (nb == 0)
		ret[0] = '0';
	while (nb > 0)
	{
		if (nb % base >= 10)
			ret[size] = nb % base + 'a' - 10;
		else
			ret[size] = nb % base + 48;
		nb = nb / base;
		size--;
	}
	return (ret);
}
