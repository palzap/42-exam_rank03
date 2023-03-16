#ifndef FT_PRINTF2_H
# define FT_PRINTF2_H

# include <unistd.h>
# include <stdarg.h>

int ft_printf2(const char *str, ...);
int ft_putstr(char *str);
int ft_putnumber(long long int number, int base);

#endif