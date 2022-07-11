/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:02:33 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/11 16:28:15 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*arr;
	int		size;

	arr = lst;
	size = 0;
	if (!lst)
		return (0);
	while (arr)
	{
		size++;
		arr = arr->next;
	}
	return (size);
}
