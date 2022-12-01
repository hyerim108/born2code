#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int result = 0;
    
    if (!str)
        result += ft_putstr("(null)");
    else
    {
        while (str[result])
        {
            ft_putchar(str[result]);
            result++;
        }
    }
    return (result);
}

int ft_putnbr(int number)
{
    int result = 0;
    
    if (number == -2147483648)
        return (write(1, "-2147483648", 11));
    if (number < 0)
    {
        result += ft_putchar('-');
        number *= -1;
    }
    if (number > 9)
        result += ft_putnbr(number / 10);
    result += ft_putchar(number % 10 + '0');
    return (result);
}

int ft_change_b(char *h_b, unsigned int n, unsigned int size)
{
    int result = 0;
    if (n > size - 2)
    {
        result += ft_change_b(h_b, n / size, size);
        n %= size;
    }
    ft_putchar(h_b[n]);
    result++;
    return (result);
}

int ft_putnbr_sx(int number)
{
    int n = (unsigned int)number;
    int result = 0;
    int size = 0;
    char *h_b = "0123456789abcdef";
    
    while(h_b[size])
        size++;
    result += ft_change_b(h_b, n, size);
    return (result);
}

int ft_putType(va_list ap, const char *str, int *i, int result)
{
    (*i)++;
    
    if (str[*i] == 'c')
        result += ft_putchar(va_arg(ap, int));
    else if (str[*i] == 's')
        result += ft_putstr(va_arg(ap, char *));
    else if (str[*i] == 'd')
        result += ft_putnbr(va_arg(ap, int));
    else if (str[*i] == 'x')
        result += ft_putnbr_sx(va_arg(ap, int));
    else if (str[*i] == '%')
        result += ft_putchar('%');
    return (result);
}

int ft_printf(const char *str, ...)
{
    int index;
    int *i;
    int result;
    va_list ap;
    
    va_start(ap, str);
    index = 0;
    i = &index;
    result = 0;
    while (str[*i])
    {
        if (str[*i] == '%')
        {
            if (str[(*i) + 1])
                result += ft_putType(ap, str, i, 0);
        }
        else
            result += ft_putchar(str[*i]);
        (*i)++;
    }
    return (result);
}
