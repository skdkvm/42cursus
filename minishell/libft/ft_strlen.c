/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:22 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:23 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

size_t	ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
