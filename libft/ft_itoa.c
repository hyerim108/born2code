/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:29:20 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/08 17:12:56 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_len(int n)
{
    int size;

    size = 1;
    if (n < 0)
    {
        size++;
        n = -n;
    }
    while (n > 9)
    {
        n /= 10;
        size++;
    }
    return (size);
}

char	*ft_itoa(int n)
{
    char    *arr;
    int     len;

    len = ft_len(n) - 1;
    arr = malloc(sizeof(char) * len + 1);
    if (!arr)
        return (0);
    arr[len] = 0;
    if (!n)
        arr[0] = '0';
    if (n < 0)
        arr[0] = '-';
    while (n)
    {
        if (n > 0)
            arr[len] = n % 10 + '0';
        else 
            arr[len] = -(n % 10) + '0';
        n /= 10;
        len--;
    }
    return (arr);
}