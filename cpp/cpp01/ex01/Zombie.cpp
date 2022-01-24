/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:30:51 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/24 18:07:08 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// 생성자1 호출시 출력
Zombie::Zombie(void)
{
    std::cout << "Zombies is comming!!!" << std::endl;
}
// 생성자2 호출시 std::string name
Zombie::Zombie(std::string name)
{
    this->name_ = name;
}
// 소멸시 출력
Zombie::~Zombie()
{
    std::cout << "<" << this->name_ << "> Zombie is dead" << std::endl;
}
// announce 호출시 출력
void    Zombie::announce(void) const
{
    std::cout << "<" << this->name_ << "> BraiiiiiiinnnzzzZ..." << std::endl;
}