/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:42:27 by seushin           #+#    #+#             */
/*   Updated: 2021/02/24 22:14:07 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int			ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int			ft_putnstr(char *str, int n)
{
	return (write(1, str, n));
}
