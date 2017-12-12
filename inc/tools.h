/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:34:18 by yfuks             #+#    #+#             */
/*   Updated: 2017/12/12 13:42:35 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# define BUFF_SIZE 1
# define STD_IN 1
# define STD_ERR 2
# include <unistd.h>
# include <stdlib.h>
# define SPACE	' '
# define TAB 	'\t'

char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strsub2(char *str, unsigned int start, size_t len);
char			**ft_split_t_sp(const char *s, char c, char d);
char			*ft_strtrim(const char *s);
int				ft_strlen(const char *s);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(const char *s, int fd);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(char c);
int				ft_isspace(char c);
int				ft_atoi(char *str);
long int		ft_atol(char *str);
char			*ft_strdup(const char *s1);
void			ft_bzero(void *s, size_t n);
char			*ft_uctoa_base(unsigned char nb, int base);
char			*ft_ustoa_base(unsigned short nb, int base);
char			*ft_uitoa_base(unsigned int nb, int base);
void			split_int_in_char(char integer[4], unsigned int value);
int				get_next_line(const int fd, char **line);
int				ft_strequ(char *s1, char *s2);
void			*ft_memalloc(size_t size);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
unsigned int	reverse_uint(unsigned int n);
char			ctoc(char tab[1]);
short			ctos(char tab[2]);
int				ctoi(char tab[4]);
void			ft_put_hex_fd(unsigned int n, int fd, int len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strndup(char **s, int c);
int				ft_realloc(char **rest);
char			**ft_strsplit(char const *s, char c, char **av);
char			*ft_trim(char *str);

#endif
