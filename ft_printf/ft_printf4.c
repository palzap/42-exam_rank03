#include "ft_printf4.h"

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

int ft_putnbr(long long int number, int base)
{
	char	*ba;
	int	count;

	count = 0;
	ba = "0123456789abcdef";
	if (number < 0)
	{
		count += write(1, "-", 1);
		number *= -1;
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

int ft_printf(char *str, ...)
{
	va_list	args;
	int	count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'i')
				count += ft_putnbr(va_arg(args, int), 10);
			else if (*str == 'x')
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

int main(void)
{
    int i = 42;
    int j = -42;
    char *str = "ola ola";
    int x;
    int y;

    x = ft_printf("vamos testar %s, %i, %x\n", str, j, i);
    y = printf("vamos testar %s, %i, %x\n", str, j, i);
	printf("%i, %i\n", x, y);
	ft_printf("%", str, j, i);
	printf("%", str, j, i);
    return (0);
}