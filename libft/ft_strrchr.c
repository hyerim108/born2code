/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:54:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/06 18:16:01 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    unsigned char *str;
    char *point;
    
    str = (unsigned char *)s;
    while (*str)
    {
        if (*str == (unsigned char)c)
            point = (char *)str;
        str++;
    }
    if (*str == (unsigned char)c)
        return ((char *)str);
    return (point);
}