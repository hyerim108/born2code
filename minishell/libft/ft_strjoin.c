/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:56:17 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 17:22:19 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	return (s3);
}
