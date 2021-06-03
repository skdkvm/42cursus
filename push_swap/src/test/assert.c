/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seushin <seushin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:24:59 by seushin           #+#    #+#             */
/*   Updated: 2021/04/24 13:50:04 by seushin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "test.h"

void	assert_eq_i(int a, int b)
{
	if (a == b)
		printf("\033[42m[OK]\033[0m\n");
	else
	{
		printf("\033[41m[KO]\033[0m\n");
		exit(EXIT_FAILURE);
	}
}
