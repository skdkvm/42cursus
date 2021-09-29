/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:39:53 by seonggki          #+#    #+#             */
/*   Updated: 2021/09/29 20:03:01 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = temp;
	}
	*lst = NULL;
}
