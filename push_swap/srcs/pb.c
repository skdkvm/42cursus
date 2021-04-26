/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:10:32 by seonggki          #+#    #+#             */
/*   Updated: 2021/04/26 21:27:09 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*a_ptr;
	t_list	*b_ptr;

	if (a == NULL || b == NULL || (*a) == NULL)
	{
		return ;
	}
	a_ptr = (*a);
	b_ptr = (*b);
	ft_lstadd_front(b, ft_lstnew(b_ptr->n));
	ft_lstdel_front(a);
}
