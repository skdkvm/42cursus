/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:35 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:09:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **b)
{
	t_list *ptr;
	t_list *iter;
	t_list *last;

	if (b == NULL || (*b) == NULL)
	{
		return ;
	}
	ptr = (*b);
	iter = ptr;
	last = ft_lstlast(iter);
	ft_lstadd_front(b, ft_lstnew(last->n));
	ft_lstdel_back(b);
}
