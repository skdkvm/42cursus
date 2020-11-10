/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijeong <mijeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:29:21 by mijeong           #+#    #+#             */
/*   Updated: 2020/08/15 23:29:23 by mijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../myheader.h"

int	print_err(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	print_dict_err(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

int	print_alloc_err(void)
{
	write(1, "Fail to allocate\n", 17);
	return (0);
}
