/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:29:07 by jthillar          #+#    #+#             */
/*   Updated: 2017/11/14 08:29:34 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static char	*fill_it(char *dest, const char *src, size_t start, size_t end)
{
	int i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strtrim(const char *s)
{
	size_t	start;
	size_t	end;
	char	*dest;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n') &&
			s[start])
		start++;
	if (start == end)
	{
		if (!(dest = (char*)malloc(1 * sizeof(char))))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	while ((s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n')
		&& s[end - 1])
		end--;
	dest = (char*)malloc(sizeof(char*) * (end - start + 1));
	if (dest == NULL)
		return (NULL);
	return (fill_it(dest, s, start, end));
}
