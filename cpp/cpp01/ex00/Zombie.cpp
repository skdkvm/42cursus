/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:42:38 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 17:14:08 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    name_ = "Zombie";
}

Zombie::Zombie(std::string name) : name_(name)
{
    return ;
}

Zombie::~Zombie()
{
    std::cout << "<" << name_ << "> Zombie is dead" << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << "<" << name_ << "> BraiiiiiiinnnzzzZ..." << std::endl;
}