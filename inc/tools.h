
#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>

int			ft_strlen(const char *s);
void		ft_putstr_fd(const char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(char c);
int			ft_isspace(char c);
int			ft_atoi(char *str);
long int	ft_atol(char *str);
char		*ft_itoa_base(int nb, int base);
int			get_next_line(const int fd, char **line);
int			ft_strequ(char *s1, char *s2);
void   		*ft_memalloc(size_t size);

#endif
