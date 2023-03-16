#ifndef FT_PRINTF4_H
# define FT_PRINTF4_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int ft_putstr(char *str);
int ft_putnbr(long long int number, int base);
int ft_printf(char *str, ...);

#endif