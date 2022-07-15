/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:55:01 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/15 17:03:01 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	result;

	result = 0;
	if (nbr == -2147483648)
	{
		result += write(1, "-2147483648", 11);
		return (result);
	}
	if (nbr < 0)
	{
		result += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		result += ft_putnbr(nbr / 10);
	result += ft_putchar(nbr % 10 + '0');
	return (result);
}
