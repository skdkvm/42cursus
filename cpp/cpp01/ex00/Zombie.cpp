/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:42:38 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/24 17:20:14 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// 생성자1 호출시 디폴트 값으로 "Zombie"
Zombie::Zombie()
{
    name_ = "Zombie";
}
// 생성자2 호출시 std::string name
Zombie::Zombie(std::string name) : name_(name)
{
    return ;
}
// 소멸시 출력
Zombie::~Zombie()
{
    std::cout << "<" << name_ << "> Zombie is dead" << std::endl;
}
// announce 호출시 출력
void    Zombie::announce(void) const
{
    std::cout << "<" << name_ << "> BraiiiiiiinnnzzzZ..." << std::endl;
}