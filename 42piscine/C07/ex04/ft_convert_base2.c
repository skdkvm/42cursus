/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 02:41:24 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/20 02:42:05 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_whitespace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int		match_base(char *base, char str)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_base_valid(char *base, int *cnt)
{
	int		i;
	int		j;

	*cnt = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_check_whitespace(base[i]))
			return (0);
		*cnt = *cnt + 1;
		++i;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		++i;
	}
	return (1);
}

void	ft_nbr_size(long long num, int convert, int *size)
{
	if (num >= (long long)convert)
	{
		ft_nbr_size(num / convert, convert, size);
		ft_nbr_size(num % convert, convert, size);
	}
	else
		*size = *size + 1;
}
