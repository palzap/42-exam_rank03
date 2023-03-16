#include "ft_printf2.h"

int ft_putnumber(long long int number, int base)
{
    char *ba;
    int count;

    ba = "0123456789abcdef";
    count = 0;
    if (number < 0)
    {
        number *= -1;
        count += write(1, "-", 1);
    }
    if (number >= base)
        count += ft_putnumber(number / base, base);
    count += write(1, &ba[number % base], 1);
    return (count);
}

int ft_putstr(char *str)
{
    int count;

    count = 0;
    if (!str)
        str = "(null)";
    while (*str)
    {
        count += write(1, str, 1);
        str++;
    }
    return (count);
}

int ft_printf2(const char *str, ...)
{
    int count;
    va_list args;

    count = 0;
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'x')
                count += ft_putnumber(va_arg(args, unsigned int), 16);
            else if (*str == 'd' || *str == 'i')
                count += ft_putnumber(va_arg(args, int), 10);
            else if (*str == 's')
                count += ft_putstr(va_arg(args, char *));
        }
        else
            count += write(1, str, 1);
        str++;
    }
    return (count);
}

#include <stdio.h>

int	main(void)
{
	int i = -42;
	int j = 42;
	char	*str = 0;
	int k = 0;
	int	x = 0;

	k = ft_printf2("bora testar\n %d\n %x\n %s\n", j, i, str);
	x = printf("bora testar\n %d\n %x\n %s\n", j, i, str);
	printf("%i, %i\n", k, x);
	return (0);
}