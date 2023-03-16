#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *ft_strjoin(char *str1, char *str2);
char    *ft_strdup(char *str);
int ft_check_newline(char *str);
int	ft_strlen(char *str);

#endif