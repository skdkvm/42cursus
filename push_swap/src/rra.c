/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:34 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:09:05 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list *ptr;
	t_list *iter;
	t_list *last;

	if (a == NULL || (*a) == NULL)
	{
		return ;
	}
	ptr = (*a);
	iter = ptr;
	last = ft_lstlast(iter);
	ft_lstadd_front(a, ft_lstnew(last->n));
	ft_lstdel_back(a);
}
