/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:30:48 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/24 18:11:46 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *horde;
    int     N;

    N = 10;
    horde = zombieHorde(N, "Legion");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete [] horde;
    return (0);
}