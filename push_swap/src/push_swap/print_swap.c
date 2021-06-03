/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:27:40 by seonggki          #+#    #+#             */
/*   Updated: 2021/06/03 12:27:23 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_push(t_stack *from, t_stack *to, char *str)
{
	push(from, to);
	print_string(str);
}

void		print_swap(t_stack *s, char *str)
{
	swap(s);
	print_string(str);
}

void		print_rotate(t_stack *s, char *str)
{
	rotate(s);
	print_string(str);
}

void		print_revers_rotate(t_stack *s, char *str)
{
	revers_rotate(s);
	print_string(str);
}

void		print_both(void (*f)(), t_stack *a, t_stack *b, char *str)
{
	f(a);
	f(b);
	print_string(str);
}
