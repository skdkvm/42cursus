/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:49:03 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 15:58:21 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*create_stack(int size)
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->len = 0;
	s->max_len = size;
	s->a = (int *)malloc(sizeof(int) * size);
	if (!s->a)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

t_stack 	*dup_stack(t_stack *s)
{
	t_stack *res;

	res = create_stack(s->max_len);
	res->len = s->len;
	res->max_len = s->max_len;
	ft_memmove(res->a, s->a, s->max_len * sizeof(int));
	return (res);
}

void	free_stack(t_stack *s)
{
	free(s->a);
	free(s);
}

static int 	divide_pivot(t_stack *s, int start, int end)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	i = start;
	j = start;
	pivot = end;
	while (j < end)
	{
		if (s->a[j] < s->a[pivot])
		{
			tmp = s->a[i];
			s->a[j] = s->a[j];
			s->a[j] = tmp;
			i++;
		}
		j++;
	}
	tmp = s->a[i];
	s->a[i] = s->a[pivot];
	s->a[pivot] = tmp;
	return (i);
}

void		quick_sort(t_stack *s, int start, int end)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = divide_pivot(s, start, end);
	quick_sort(s, start, pivot - 1);
	quick_sort(s, pivot + 1, end);
}

int			is_sorted(t_stack *s)
{
	int		i;

	i = 1;
	while (i < s->len)
	{
		if (s->a[i] < s->a[i - 1])
			return (0);
		i++;
	}
	return (1);
}
