/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:16:57 by seonggki          #+#    #+#             */
/*   Updated: 2021/06/03 13:34:01 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		increase_stack(t_stack *s)
{
	int		*tmp;
	int		new_len;

	new_len = s->max_len * 2;
	tmp = (int *)malloc(sizeof(int) * new_len);
	if (!tmp)
		return (1);
	ft_memmove(tmp, s->a, s->len * sizeof(int));
	free(s->a);
	s->a = tmp;
	s->max_len = new_len;
	return (0);
}

void	pop_front(t_stack *s)
{
	if (s->len == 0)
		return ;
	ft_memmove(s->a, (s->a + 1), (s->len - 1) * sizeof(int));
	s->len--;
}

void	push_front(t_stack *s, int n)
{
	if (s->max_len < s->len + 1)
		increase_stack(s);
	ft_memmove((s->a + 1), s->a, s->len * sizeof(int));
	s->a[0] = n;
	s->len++;
}

void	push_back(t_stack *s, int n)
{
	if (s->max_len < s->len + 1)
		increase_stack(s);
	s->a[s->len] = n;
	s->len++;
}
