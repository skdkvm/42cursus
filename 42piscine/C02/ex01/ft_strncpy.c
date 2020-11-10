/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 04:29:05 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/08 20:39:31 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned	int	i;
	int				count;

	i = 0;
	count = 0;
	while (i < n)
	{
		if (count == 1 || src[i] == '\0')
		{
			dest[i] = '\0';
			count = 1;
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
