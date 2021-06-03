/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_do_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:17:10 by seushin           #+#    #+#             */
/*   Updated: 2021/04/24 20:42:51 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "test.h"
#include "libft.h"
#include "push_swap.h"

#define INST_FILE "./test_tmp"

/*
** dep: stack.h libft
*/

static	int		is_eq(t_stack *a, t_stack *b, t_stack *ra, t_stack *rb)
{
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (a->a[i] != ra->a[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < b->len)
	{
		if (b->a[i] != rb->a[i])
			return (0);
		i++;
	}
	return (1);
}

static int		test_do_op(t_stack *a, t_stack *b, char *comment)
{
	int		res;
	int		fd;
	int		i;

	if ((fd = open(INST_FILE, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	res = do_op(fd, a, b);
	printf("\n- test: %15s ----------\n\na |", comment);
	i = a->len - 1;
	while (0 <= i)
	{
		printf("%3d", a->a[i]);
		i--;
	}
	printf("\nb |");
	i = b->len;
	while (0 <= i)
	{
		printf("%3d", b->a[i]);
		i--;
	}
	printf("\n------------------------------------\n");
	close(fd);
	return (res);
}

static void		init(t_stack **a, t_stack **b, const char *inst)
{
	int			fd;
	int			i;

	if ((fd = open(INST_FILE, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
		printf("Fail.\n");
	write(fd, inst, ft_strlen(inst));
	close(fd);
	*a = create_stack(S_LEN);
	*b = create_stack(S_LEN);
	i = 0;
	while (i++ < 10)
		push_back(*a, i);
}

static void		clear(t_stack *a, t_stack *b)
{
	char		*cmd;

	cmd = ft_strjoin("rm -f ", INST_FILE);
	system(cmd);
	free_stack(a);
	free_stack(b);
	a = NULL;
	b = NULL;
}

int				main(void)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*ra;
	t_stack		*rb;

	ra = create_stack(S_LEN);
	rb = create_stack(S_LEN);
	init(&a, &b, "sa\npb\npb\nrra\nrrr\n");
	swap(ra);
	push(ra, rb);
	push(ra, rb);
	rev_rotate(ra);
	exec_both(&rev_rotate, ra, rb);
	assert_eq_i(test_do_op(a, b, "sa, pb, pb, rra rrr") ||
			is_eq(a, b, ra, rb), EXIT_SUCCESS);
	clear(a, b);
	init(&a, &b, "sa\npb\npc\npb\n");
	assert_eq_i(test_do_op(a, b, "wrong instruction") ||
			is_eq(a, b, ra, rb), EXIT_FAILURE);
	clear(a, b);
	printf("Done.\n");
	return (0);
}
