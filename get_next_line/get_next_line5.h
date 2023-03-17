#ifndef GET_NEXT_LINE5_H
# define GET_NEXT_LINE5_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int	ft_strlen(char *str);
int	ft_check_char(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_trim(char *line);
char	*ft_get(int fd, char *buffer, char *stash);
char	*get_next_line(int fd);

#endif