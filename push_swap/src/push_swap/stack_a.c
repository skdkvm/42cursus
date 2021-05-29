/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:50:55 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 18:42:36 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		split_chunk(t_stack *pivot, t_stack *a)
{
	int		front;
	int		mid;
	int		back;
	t_stack *s;

	s = dup_stack(a);
	quick_sort(s, 0, s->len - 1);
	front = get_index(s, pivot->a[0]);
	back = get_index(s, pivot->a[1]);
	mid = front + ((back - front) / 2) + 1;
	if (mid != back)
	{
		push_front(pivot, s->a[mid]);
		swap(pivot);
	}
	free_stack(s);
}

int			get_chunk_len(t_stack *pivot, t_stack *a)
{
	int		front;
	int		back;
	t_stack *s;

	s = dup_stack(a);
	quick_sort(s, 0, s->len - 1);
	front = get_index(s, pivot->a[0]);
	back = get_index(s, pivot->a[1]);
	free_stack(s);
	return (back - front);
}

void		sort_to_rotate(t_stack *a)
{
	int		min;

	min = get_min_index(a);
	while (min != 0)
	{
		if (min < a->len - min)
			print_rotate(a, "ra");
		else
			print_revers_rotate(a, "rra");
		min = get_min_index(a);
	}
}
