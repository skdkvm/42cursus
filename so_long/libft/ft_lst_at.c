/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:00:53 by seonggki          #+#    #+#             */
/*   Updated: 2021/12/12 18:04:51 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list **begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*ptr;

	if (!begin_list)
		return (NULL);
	ptr = *begin_list;
	i = 0;
	while (ptr && i < nbr)
	{
		i++;
		ptr = ptr->next;
	}
	if (i < nbr && !ptr)
		return (NULL);
	return (ptr);
}
