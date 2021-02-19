/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:37:18 by seonggki          #+#    #+#             */
/*   Updated: 2021/01/25 21:21:57 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format(const char *str, int *i, va_list args)
{
	t_flag	flag;
	int		len;

	*i += 1;
	flag_init(str, i, &flag, args);
	if (str[*i] == 'd' || str[*i] == 'i')
		len = print_int(va_arg(args, int), flag);
	else if (str[*i] == 'u')
		len = print_int(va_arg(args, unsigned int), flag);
	else if (str[*i] == 'c')
		len = print_char(va_arg(args, int), flag);
	else if (str[*i] == 's')
		len = print_str(va_arg(args, char*), flag);
	else if (str[*i] == 'x' || str[*i] == 'X')
		len = print_hex(va_arg(args, unsigned int), flag, str[*i]);
	else if (str[*i] == 'p')
		len = print_mem(va_arg(args, unsigned long), flag);
	else
		len = print_none(str[*i], flag);
	if (str[*i] != '\0')
		*i += 1;
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += format(str, &i, args);
		else
		{
			write(1, &str[i++], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
