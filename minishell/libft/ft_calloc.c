/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoh <sanoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:30:00 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 17:14:02 by sanoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(n * size);
	if (s != NULL)
		ft_bzero(s, n * size);
	return ((void *)s);
}
