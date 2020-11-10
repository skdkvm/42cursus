/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:06:38 by seonggki          #+#    #+#             */
/*   Updated: 2020/08/15 18:07:57 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	num;

	num = 1;
	if (power < 0)
	{
		return (0);
	}
	while (power)
	{
		num *= nb;
		power--;
	}
	return (num);
}
