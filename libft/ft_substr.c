/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:34:05 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/07 14:26:40 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *arr;
    unsigned int    i;
    unsigned int    x;

    i = 0;
    x = 0;
    if (!s)
        return (0);
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    arr = (char *)malloc(sizeof(char) * len + 1);
    if (!arr)
        return (0);
    while (s[start] != '\0' && i < len)
    {
        arr[i++] = s[start++];
    }
    arr[i] = '\0';
    return (arr);
}