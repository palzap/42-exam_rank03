#include "ft_printf5.h"

int	ft_putstr(char *str)
{
	int	count;

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

int	ft_putnbr(long long int number, int base)
{
	int	count;
	char	*ba;

	count = 0;
	ba = "0123456789abcdef";
	if (number < 0)
	{
		number *= -1;
		count += write(1, "-", 1);
	}
	if (number < base)
		count += write(1, &ba[number], 1);
	else
	{
		count += ft_putnbr(number / base, base);
		count += ft_putnbr(number % base, base);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;
	
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
				count += ft_putnbr(va_arg(args, int), 10);
			else if(*str == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
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
	int	i = -42;
	int j = 50;
	char	*str = "teste teste teste";
	int	x = 0;
	int	y = 0;
	
	x = ft_printf("testing\nd - %d\nx - %x\ns - %s\n", i, j, str);
	y = printf("testing\nd - %d\nx - %x\ns - %s\n", i, j, str);
	printf("%i | %i\n", x, y);
	return (0);
}