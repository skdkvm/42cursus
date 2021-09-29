/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:59:04 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 14:59:05 by seonggki         ###   ########.fr       */
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
