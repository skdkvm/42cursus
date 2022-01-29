/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:42:39 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 17:15:08 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    private:
            std::string     name_;
    public:
            Zombie();
            Zombie(std::string str);
            ~Zombie();
            void    announce(void) const;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif