#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int ft_printf(char *str, ...);
int	ft_putstr(char *str);
int	ft_putnumber(long number);
int	ft_puthexa(unsigned long number);


#endif