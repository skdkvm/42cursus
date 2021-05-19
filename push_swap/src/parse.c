/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:04:20 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/19 19:10:30 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	integer(char *arg)
{
	long long int	res;
	int				i;

	res = 0;
	i = 1;
	if (*arg == '-')
	{
		i = -1;
		arg++;
	}
	else if (*arg == '+')
		arg++;
	while (ft_isdigit(*arg))
	{
		res = res * 10 + (i * (*arg - '0'));
		if (res < MIN_INT || MAX_INT < res)
			return (0);
		arg++;
	}
	return (1);
}

static int	is_dup(t_stack *s, int n)
{
	int				i;

	i = 0;
	while (i < s->len)
	{
		if (s->a[i] == n)
			return (1);
		i++;
	}
	return (0);
}

static int	check_arg(char *arg, t_stack *s, int n)
{
	int				i;

	i = 0;
	while (*arg && *arg == ' ')
		arg++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i] != '\0')
		return (1);
	if (!integer(arg) || is_dup(s, n))
		return (1);
	return (0);
}

static int	free_split(char **strs, int splitted)
{
	int				i;

	if (!splitted)
		return (1);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (1);
}

int			parse(t_stack *s, int argc, char **argv)
{
	int				i;
	int				n;
	int				splitted;

	i = 1;
	splitted = 0;
	if (argc - i == 1)
	{
		i = 0;
		argc = count_words(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		splitted = 1;
	}
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (check_arg(argv[i], s, n))
			return (free_split(argv, splitted));
		push_back(s, n);
		i++;
	}
	free_split(argv, splitted);
	return (0);
}
