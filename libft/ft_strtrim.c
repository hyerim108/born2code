/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:22 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/07 18:08:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_valid(char const *set, char c)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *arr;
    size_t  start;
    size_t  last;
    size_t  i;
    
    start = 0;
    last = ft_strlen(s1) - 1;
    while (s1[start] && is_valid(set, s1[start]))
        start++;
    while (s1[last] && is_valid(set, s1[last]))
    {
        if (last < start)
            return (ft_strdup(""));
        last--;
    }
    arr = (char *)malloc(sizeof(char) * (start + last + 1));
    if (!arr)
        return (0);
    while (start <= last)
        arr[i++] = s1[start++];
    arr[i] = 0;
    return (arr);
}