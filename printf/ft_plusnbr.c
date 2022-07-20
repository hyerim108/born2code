/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plusnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:23:41 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/20 14:50:44 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_plusnbr(int nbr)
{
	int				result;
	unsigned int	n;

	result = 0;
	n = (unsigned int)nbr;
	if (n > 9)
		result += ft_plusnbr(n / 10);
	result += ft_putchar(n % 10 + '0');
	return (result);
}
