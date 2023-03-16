#ifndef FT_PRINTF3_H
# define FT_PRINTF3_H

# include <unistd.h>
# include <stdarg.h>

int ft_printf3(const char *str, ...);
int ft_putstr(char *str);
int ft_putnumber(long long int number, int base);

#endif