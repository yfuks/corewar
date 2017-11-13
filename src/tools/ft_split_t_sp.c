/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_t_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alansiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:49:33 by alansiva          #+#    #+#             */
/*   Updated: 2017/11/13 18:22:44 by alansiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

size_t		ft_count_word(char const *str, char c, char d)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c || str[i] == d)
			i++;
		if (str[i] != c && str[i] != d && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != d && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c, char d)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c || s[i] == d)
		i++;
	while (s[i] != c && s[i] != d && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_split_t_sp(char const *s, char c, char d)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	i = 0;
	j = 0;
	if (!s || !(tab = (char **)malloc(sizeof(*tab) *
					(ft_count_word(s, c, d) + 1))))
		return (NULL);
	while (i < ft_count_word(s, c, d))
	{
		k = 0;
		if (!(tab[i] = ft_strnew(ft_word_len(&s[j], c, d) + 1)))
			tab[i] = NULL;
		while (s[j] == c || s[j] == d)
			j++;
		while (s[j] != c && s[j] != d && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
