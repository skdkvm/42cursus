/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:30:51 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 17:48:43 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombies is comming!!!" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name_ = name;
}

void    Zombie::set_name(std::string name)
{
    this->name_ = name;
}

Zombie::~Zombie()
{
    std::cout << "<" << this->name_ << "> Zombie is dead" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << "<" << this->name_ << "> BraiiiiiiinnnzzzZ..." << std::endl;
}