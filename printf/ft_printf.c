/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:46:11 by hyerimki          #+#    #+#             */
/*   Updated: 2022/10/18 13:36:34 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	int		i;
	va_list	ap;

	result = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
				result += ft_putsymbol(format, ++i, ap);
		}
		else
			result += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (result);
}
