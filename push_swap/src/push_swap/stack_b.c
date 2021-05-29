/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:50:56 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 16:50:13 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_close_top(t_stack *s)
{
	int		min;
	int		max;

	min = get_min_index(s);
	max = get_max_index(s);
	if (min == 0 || max == 0)
		return (0);
	if (min < s->len - min || max < s->len - max)
		return (1);
	else
		return (0);
}

void			empty_b(t_stack *a, t_stack *b)
{
	int		min;
	int		max;

	while (b->len)
	{
		min = b->a[get_min_index(b)];
		max = b->a[get_max_index(b)];
		if (a->a[0] < min)
		{
			if (is_close_top(b))
				print_both(rotate, a, b, "rr");
			else
				print_rotate(a, "ra");
		}
		else if (b->a[0] == max || b->a[0] == min)
			print_push(b, a, "pa");
		else if (is_close_top(b))
			print_rotate(b, "rb");
		else
			print_revers_rotate(b, "rrb");
	}
}

void			recursive_split_b(t_stack *a, t_stack *b, t_stack *pivot)
{
	int		iter;
	int		median;

	if (b->len == 0)
		return ;
	median = get_median(b);
	iter = b->len - (b->len / 2);
	while (iter && b->len)
	{
		if (median <= b->a[0])
		{
			print_push(b, a, "pa");
			iter--;
		}
		else if (get_min_index(b) == 0)
		{
			print_push(b, a, "pa");
			if (b->len)
				print_rotate(a, "ra");
		}
		else
			print_rotate(b, "rb");
	}
	push_front(pivot, median);
	recursive_split_b(a, b, pivot);
}
