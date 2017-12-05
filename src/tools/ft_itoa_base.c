/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:13:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/05 11:35:08 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			len_number(long int nb, int base)
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

char				*ft_itoa_base(int nb, int base)
{
	int				size;
	long int		nbl;
	char			*ret;

	nbl = nb;
	size = len_number(nbl, base);
	if (!(ret = (char*)malloc(sizeof(size))))
		return (0);
	ret[size] = '\0';
	size -= 1;
	if (nbl < 0)
	{
		if (base == 10)
			ret[0] = '-';
		nbl = -nbl;
	}
	if (nbl == 0)
		ret[0] = '0';
	while (nbl > 0)
	{
		if (nbl % base > 10)
			ret[size] = nbl % base + 55;
		else
			ret[size] = nbl % base + 48;
		nbl = nbl / base;
		size--;
	}
	return (ret);
}
