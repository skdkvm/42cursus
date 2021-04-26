/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:00:09 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:02:01 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst1, t_list *lst2)
{
	int	tmp;

	tmp = lst1->n;
	lst1->n = lst2->n;
	lst2->n = tmp;
}

void	sa(t_list **a)
{
	t_list *ptr;

	if (a == NULL || ft_lstsize((*a)) <= 1)
		return ;
	ptr = (*a);
	swap(ptr, ptr->next);
}
