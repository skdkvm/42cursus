/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:10:31 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:26:44 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*a_ptr;
	t_list	*b_ptr;

	if (a == NULL || b == NULL || (*b) == NULL)
	{
		return ;
	}
	a_ptr = (*a);
	b_ptr = (*b);
	ft_lstadd_front(a, ft_lstnew(b_ptr->n));
	ft_lstdel_front(b);
}
