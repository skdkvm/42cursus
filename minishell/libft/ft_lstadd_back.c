/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:30:35 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/11 15:30:38 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_commands **lst, t_commands *new)
{
	t_commands	*pl;

	pl = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		if (new)
		{
			while (pl->next)
				pl = pl->next;
			pl->next = new;
		}
	}
}
