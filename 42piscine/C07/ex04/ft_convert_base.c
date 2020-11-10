/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 02:41:15 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/20 02:41:41 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_check_whitespace(char c);
int		match_base(char *base, char str);
int		ft_base_valid(char *base, int *cnt);
int		ft_nbr_size(long long num, int convert, int *size);

int		ft_atoi_b(char *str, char *base, int convert)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (ft_check_whitespace(*str))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (match_base(base, *str) != -1)
	{
		res *= convert;
		res += match_base(base, *str);
		str++;
	}
	return (res * sign);
}

char	*ft_putnbr_b(int nbr, char *base, int convert)
{
	char		*res;
	long long	num;
	int			size;

	size = 0;
	num = nbr;
	if (nbr < 0)
	{
		size = 1;
		num *= -1;
	}
	ft_nbr_size(num, convert, &size);
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (0);
	if (nbr < 0)
		res[0] = '-';
	res[size] = '\0';
	while (size && !(size == 1 && nbr < 0))
	{
		res[--size] = base[num % convert];
		num /= convert;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int len_f;
	int len_t;

	if (!(ft_base_valid(base_from, &len_f) && ft_base_valid(base_to, &len_t)))
		return (0);
	return (ft_putnbr_b(ft_atoi_b(nbr, base_from, len_f), base_to, len_t));
}
