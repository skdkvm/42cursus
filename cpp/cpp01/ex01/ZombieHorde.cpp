/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:30:52 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 17:54:13 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
    {
        std::stringstream   str;
        str << (i + 1);
        horde[i].set_name(name + "(" + str.str() + ")");
    }
    return (horde);
}