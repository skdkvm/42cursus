/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:05:30 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:05:35 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp;

	tmp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (tmp);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	move_collect(t_info	*info)
{
	info->collect--;
	ft_putstr_fd("Collectibles left: ", 1);
	ft_putnbr_fd((int)info->collect, 1);
	ft_putchar_fd('\n', 1);
}
