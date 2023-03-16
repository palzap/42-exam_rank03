#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int	ft_check_newline(char *str);
char	*ft_strdup(char *str);
char	*ft_join(char *str1, char *str2);
int	ft_strlen(char *str);
char	*ft_trim(char *line);
char	*ft_get_all(int fd, char *buffer, char *stash);

#endif