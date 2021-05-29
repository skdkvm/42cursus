/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:11:41 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 18:23:14 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_top_linked_bot(t_stack *a, t_stack *b)
{
	int		i;
	int		res;
	t_stack	*tmp;

	tmp = dup_stack(a);
	i = 0;
	while (i < b->len)
	{
		push_back(tmp, b->a[i]);
		i++;
	}
	quick_sort(tmp, 0, tmp->len);
	if (get_index(tmp, a->a[0]) == get_index(tmp, a->a[a->len - 1]) + 1
			&& get_index(tmp, a->a[a->len - 1] < a->len))
		res = 1;
	else
		res = 0;
	free_stack(tmp);
	return (res);
}

static int	is_first_split(int len, int chunk_len)
{
	int		median;

	median = (len / 2.0) + 0.5;
	return (median == chunk_len);
}

void		push_chunk_to_b(
				t_stack *a, t_stack *b, t_stack *pivot, int chunk_len)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < chunk_len)
	{
		if (pivot->a[0] <= a->a[0] && a->a[0] < pivot->a[1])
		{
			if (!is_first_split(a->len, chunk_len) && is_top_linked_bot(a, b))
				print_rotate(a, "ra");
			else
				print_push(a, b, "pb");
			i++;
		}
		else
		{
			if (pivot->a[1] <= a->a[0])
				count++;
			print_rotate(a, "ra");
		}
	}
	if (a->len != b->len && a->len + 1 != b->len)
		while (count--)
			print_revers_rotate(a, "rra");
}
