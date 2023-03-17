#ifndef FT_PRINTF5_H
# define FT_PRINTF5_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putnbr(long long int number, int base);
int	ft_printf(const char *str, ...);

#endif