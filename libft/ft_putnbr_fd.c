/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:22:01 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/07 13:28:46 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    if (fd < 0)
        return ;
    if (n == -2147483648)
        write(fd, "-2147483648", 11);
    else if (n < 0)
    {
        write(fd, "-", 1);
        ft_putnbr_fd(-n, fd);
    }
    if (n > 9)
        ft_putnbr_fd(n / 10, fd);
    else
        ft_putchar_fd(n % 10 + '0', fd);
}