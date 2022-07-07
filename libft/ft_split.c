/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:42:35 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/07 18:01:50 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_free(char **str)
{
    size_t  i;
    
    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (0);
}

size_t  ft_wordcount(char *s, char c)
{
    size_t  i;
    size_t  size;

    size = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            i++;
        else
        {
            size++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (size);
}
char    *ft_cpy(char const *s, char c)
{
    char    *arr;
    size_t  i;
    size_t  size;

    i = 0;
    size = 0;
    while (s[size] && s[size] != c)
        size++;
    arr = (char *)malloc(sizeof(char) * size + 1);
    if (!arr)
        return (0);
    while (i < size)
    {
        arr[i] = s[i];
        i++;
    }
    arr[i] = '\0';
    return (arr);
}
char	**ft_split(char const *s, char c)
{
    char    **arr;
    size_t  size;
    size_t  i;
    
    i = 0;
    size = ft_wordcount((char *)s, c);
    arr = (char **)malloc(sizeof(char *) * size + 1);
    if (!arr)
        return (0);
    while(*s)
    {
        while (*s && *s == c)
            s++;
        if (*s && *s != c)
        {
            arr[i] = ft_cpy(s, c);
            if (!arr[i])
                return (ft_free(arr));
            while (*s && *s != c)
                s++;
            i++;
        }
    }
    arr[i] = 0;
    return (arr);
}