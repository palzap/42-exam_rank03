#include "ft_printf.h"

int	ft_puthexa(unsigned long number)
{
	char	*base;
	int	count;

	base = "0123456789abcdef";
	count = 0;
	if (number < 16)
	{
		count += write(1, &base[number], 1);
	}
	else
	{
		count += ft_puthexa(number / 16);
		count += ft_puthexa(number % 16);
	}
	return (count);
}


int	ft_putnumber(long number)
{
	char	*base;
	int	count;

	base = "0123456789";
	count = 0;
	if (number < 0)
	{
		count += write(1, "-", 1);
		number *= -1;
	}
	if (number < 10)
	{
		count += write(1, &base[number], 1);
	}
	else
	{
		count += ft_putnumber(number / 10);
		count += ft_putnumber(number % 10);
	}
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;
	
	count = 0;
	if (!*str)
		str = "(null)";
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int ft_printf(char *str, ...)
{
    va_list args;
    int count;

    count = 0;
    va_start(args, str);
    while(*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'x')
            	count += ft_puthexa(va_arg(args, unsigned int));
       		else if (*str == 'd' || *str == 'i')
            	count += ft_putnumber(va_arg(args, int));
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

	k = ft_printf("bora testar\n %i\n %x\n %s\n", j, i, str);
	x = printf("bora testar\n %i\n %x\n %s\n", j, i, str);
	printf("%i, %i\n", k, x);
	return (0);
}