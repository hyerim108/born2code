/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:26:14 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/09 18:45:02 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*arr;
	t_list	*b;

	arr = *lst;
	while (arr)
	{
		b = arr->next;
		ft_lstdelone(arr, del);
		arr = b;
	}
	*lst = 0;
}
