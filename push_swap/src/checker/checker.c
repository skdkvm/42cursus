/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:45:59 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 18:35:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (1 < argc)
	{
		a = create_stack(INIT_LEN);
		b = create_stack(INIT_LEN);
		if (parse(a, argc, argv) == 0 &&
				operations_start(STDIN, a, b) == 0)
		{
			if (is_sorted(a) && b->len == 0)
				write(STDOUT, "OK\n", 3);
			else
				write(STDOUT, "KO\n", 3);
		}
		else
			write(STDERR, "Error\n", 6);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
