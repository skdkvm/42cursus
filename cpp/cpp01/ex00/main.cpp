/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:40:40 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 17:14:51 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "This is Stack Zombies" << std::endl;
    Zombie  zombie;
    zombie.announce();
    Zombie  zombie1("Top");
    zombie1.announce();
    Zombie  zombie2("Mid");
    zombie2.announce();
    randomChump("randomChump");

    std::cout << "This is Heap Zombies" << std::endl;
    Zombie  *heap_zombie;
    heap_zombie = newZombie("Bottom");
    heap_zombie->announce();
    delete(heap_zombie);
    return (0);
}