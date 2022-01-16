/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:32:06 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:07 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)ft_calloc((ft_strlen((char *)s) + 1), sizeof(char));
	while (str && s[++i])
		str[i] = s[i];
	return (str);
}
