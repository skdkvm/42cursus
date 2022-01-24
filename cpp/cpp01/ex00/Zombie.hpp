/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:42:39 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/24 17:18:00 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    private:
            std::string     name_;       // 멤버 변수
    public:
            Zombie();                    // 생성자 1
            Zombie(std::string str);     // 생성자 2
            ~Zombie();                   // 소멸자
            void    announce(void) const;// 멤버 함수(메서드)
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif