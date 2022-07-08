/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:29:20 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/08 18:47:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_len(int n)
{
    int size;

    size = 1;
    if (n == -2147483648)
        return (11);
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
    char *arr;
    int len;

    len = ft_len(n) - 1;
    arr = malloc(sizeof(char) * len + 1);
    
}