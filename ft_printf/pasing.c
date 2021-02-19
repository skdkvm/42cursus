/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:37:25 by seonggki          #+#    #+#             */
/*   Updated: 2021/01/25 21:22:14 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	flag_format(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
	c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_bool	flag_valid(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
	c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	if (c == '-' || c == '.' || c == '*')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str, int *i, va_list args)
{
	int num;

	num = 0;
	if (str[*i] == '.')
		*i += 1;
	if (str[*i] == '*')
	{
		num = va_arg(args, unsigned int);
		return (num);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = (str[*i] - 48) + num * 10;
		*i += 1;
	}
	*i -= 1;
	return (num);
}

void	neg_star(t_flag *flag)
{
	if (flag->precision < 0)
	{
		flag->dot = 0;
		flag->precision = 0;
	}
	else if (flag->width < 0)
	{
		flag->neg = 1;
		flag->width = -flag->width;
	}
}

void	flag_init(const char *str, int *i, t_flag *flag, va_list args)
{
	flag->neg = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->precision = 0;
	flag->width = 0;
	while (flag_format(str[*i]) == 0 && flag_valid(str[*i]))
	{
		if (str[*i] == '-')
			flag->neg = 1;
		else if (str[*i] == '0')
			flag->zero = 1;
		else if (str[*i] == '.')
		{
			flag->dot = 1;
			flag->precision = ft_atoi(str, i, args);
		}
		else if (str[*i] == '*' || (str[*i] >= '1' && str[*i] <= '9'))
			flag->width = ft_atoi(str, i, args);
		if (flag->precision < 0 || flag->width < 0)
			neg_star(flag);
		*i += 1;
	}
}
