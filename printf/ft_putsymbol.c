/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsymbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:13:15 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/15 16:58:23 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsymbol(const char *format, int i, va_list ap)
{
	int	result;
	unsigned long long memory;

	result = 0;
	if (format[i] == 'c')
		result += ft_putchar(va_arg(ap, int));
	else if(format[i] == 's')
		result += ft_putstr(va_arg(ap, char *));
	else if(format[i] == 'd' || format[i] == 'i')
		result += ft_putnbr(va_arg(ap, int));
	else if(format[i] == 'u')
		result += ft_plusnbr(va_arg(ap, int));
	else if(format[i] == 'x' || format[i] == 'X')
		result += ft_base(format[i], va_arg(ap, int));
	else if(format[i] == '%')
		result += ft_putchar('%');
	else if(format[i] == 'p')
	{
		memory = va_arg(ap, unsigned long long);
		result += ft_memory(&memory);
	}
	return (result);
}
