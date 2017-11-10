
#ifndef TOOLS_H
# define TOOLS_H

int		ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
int		get_next_line(const int fd, char **line);
int		ft_strequ(char *s1, char *s2);
char	*ft_itoa_base(intmax_t value, intmax_t base);
void    *ft_memalloc(size_t size);
#endif
