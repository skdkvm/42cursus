/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:40:51 by seonggki          #+#    #+#             */
/*   Updated: 2021/06/03 14:08:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		solve_three(t_stack *a)
{
	t_stack *tmp;

	tmp = dup_stack(a);
	rotate(tmp);
	if (is_sorted(tmp))
		print_rotate(a, "ra");
	else
	{
		rotate(tmp);
		if (is_sorted(tmp))
			print_revers_rotate(a, "rra");
		else
		{
			print_swap(a, "sa");
			if (!is_sorted(a))
				solve_three(a);
		}
	}
	free_stack(tmp);
}

void		solve_five(t_stack *a, t_stack *b)
{
	int		len;
	t_stack	*tmp;

	tmp = dup_stack(a);
	quick_sort(tmp, 0, tmp->len - 1);
	len = a->len;
	while (a->len != 3)
	{
		if (a->a[0] <= tmp->a[len % 4])
			print_push(a, b, "pb");
		else if (a->a[1] <= tmp->a[len % 4] || a->a[2] <= tmp->a[len % 4])
			print_rotate(a, "ra");
		else
			print_revers_rotate(a, "rra");
	}
	solve_three(a);
	while (b->len)
		print_push(b, a, "pa");
	if (!is_sorted(a))
		print_swap(a, "sa");
	free_stack(tmp);
}

void		solve(t_stack *a, t_stack *b, t_stack *pivot)
{
	int		chunk_len;

	if (pivot->len == 1)
		return ;
	split_chunk(pivot, a);
	chunk_len = get_chunk_len(pivot, a);
	push_chunk_to_b(a, b, pivot, chunk_len);
	if (b->len <= LIMIT_LEN)
		empty_b(a, b);
	else
	{
		recursive_split_b(a, b, pivot);
		quick_sort(pivot, 0, pivot->len - 1);
	}
	pop_front(pivot);
	solve(a, b, pivot);
	sort_to_rotate(a);
}

void		push_swap(t_stack *a, t_stack *b)
{
	t_stack	*pivot;

	if (is_sorted(a))
		return ;
	if (a->len <= 3)
		solve_three(a);
	else if (a->len <= 5)
		solve_five(a, b);
	else
	{
		pivot = create_stack(INIT_LEN);
		push_back(pivot, a->a[get_min_index(a)]);
		push_back(pivot, a->a[get_max_index(a)]);
		solve(a, b, pivot);
		free_stack(pivot);
	}
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (1 < argc)
	{
		a = create_stack(INIT_LEN);
		b = create_stack(INIT_LEN);
		if (parse(a, argc, argv) == EXIT_SUCCESS)
			push_swap(a, b);
		else
			write(STDERR, "Error\n", 6);
		free_stack(a);
		free_stack(b);
	}
	return (EXIT_SUCCESS);
}
