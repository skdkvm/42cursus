/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:17:10 by seushin           #+#    #+#             */
/*   Updated: 2021/04/24 20:44:12 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft.h"
#include "push_swap.h"

/*
** dep: parse.c stack.h ft_split.c
*/

static	int		is_eq(t_stack *s, const int *ans)
{
	int		i;

	if (!ans)
		return (0);
	i = 0;
	while (i < s->len)
	{
		if (s->a[i] != ans[i])
			return (0);
		i++;
	}
	if (i != 6)
		return (0);
	return (1);
}

static	void	print_info(t_stack *s, int argc, char **argv)
{
	int		i;

	printf("\n- test ----------------\n");
	i = 1;
	while (i < argc)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	printf("\nt_stack *s;\n{\n");
	printf("  s->len: %d\n", s->len);
	i = 0;
	while (i < s->len)
	{
		printf("  s->a[%d]: %d\n", i, s->a[i]);
		i++;
	}
	printf("}\n-----------------------\n");
}

static int		test_parse(int argc, char **argv, const int *ans)
{
	int		res;
	t_stack	*a;

	a = create_stack(S_LEN);
	res = parse(a, argc, argv);
	print_info(a, argc, argv);
	if (res == EXIT_SUCCESS && is_eq(a, ans))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int				main(void)
{
	char		**argv;
	char		*str;
	int			case_;
	const int	ans[] = { 1, 10, 100, 1000, -2147483648, 2147483647 };

	case_ = 1;
	str = "./test_parse 1 10 100 1000 -2147483648 2147483647";
	argv = ft_split(str, ' ');
	assert_eq_i(test_parse(7, argv, ans), EXIT_SUCCESS);
	case_ = 2;
	argv[1] = "1 10 100 1000 -2147483648 2147483647";
	assert_eq_i(test_parse(2, argv, ans), EXIT_SUCCESS);
	case_ = 3;
	argv[1] = "1 2 3 42 42";
	assert_eq_i(test_parse(2, argv, NULL), EXIT_FAILURE);
	case_ = 4;
	argv[1] = "1 2 3 42 2147483648";
	assert_eq_i(test_parse(2, argv, NULL), EXIT_FAILURE);
	case_ = 5;
	argv[1] = "1 2 3 42 four";
	assert_eq_i(test_parse(2, argv, NULL), EXIT_FAILURE);
	printf("Done.\n");
	return (0);
}
