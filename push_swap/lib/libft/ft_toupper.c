/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:08 by seonggki          #+#    #+#             */
/*   Updated: 2021/05/29 15:00:09 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}