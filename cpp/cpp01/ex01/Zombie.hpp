/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:33:59 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 17:53:22 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <sstream>

class   Zombie
{
    private:
            std::string     name_;
    public:
            Zombie();
            Zombie(std::string str);
            void    announce(void);
            void    set_name(std::string name);
            ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif