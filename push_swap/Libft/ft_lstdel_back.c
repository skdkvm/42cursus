/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:35:37 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/23 16:35:38 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_back(t_list **lst)
{
	t_list	*prev;
	t_list	*iter;

	if (lst == 0)
		return ;
	prev = (*lst);
	iter = (*lst)->next;
	while (iter->next != NULL)
	{
		prev = iter;
		iter = iter->next;
	}
	ft_lstdelone(iter);
	prev->next = NULL;
}
