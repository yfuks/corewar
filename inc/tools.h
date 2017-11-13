/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:34:18 by yfuks             #+#    #+#             */
/*   Updated: 2017/11/13 18:07:56 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>

int				ft_strlen(const char *s);
void			ft_putstr_fd(const char *s, int fd);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(char c);
int				ft_isspace(char c);
int				ft_atoi(char *str);
long int		ft_atol(char *str);
char			*ft_strdup(const char *s1);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa_base(int nb, int base);
char			*ft_uitoa_base(unsigned int nb, int base);
int				get_next_line(const int fd, char **line);
int				ft_strequ(char *s1, char *s2);
void   			*ft_memalloc(size_t size);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
unsigned int	reverse_uint(unsigned int n);
void			ft_put_hex_fd(unsigned int n, int fd);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif
