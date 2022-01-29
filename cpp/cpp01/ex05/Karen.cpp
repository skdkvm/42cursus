/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:20 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 16:43:12 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
    return ;
}

Karen::~Karen()
{
    return ;
}

void Karen::debug(void)
{
    std::cout << "[ DEBUG ] Karen complain " << std::endl;
}

void Karen::info(void)
{
    std::cout << "[ INFO ] Karen complain " << std::endl;
}

void Karen::warning(void)
{
    std::cout << "[ WARNING ] Karen complain " << std::endl;
}

void Karen::error(void)
{
    std::cout << "[ ERROR ] Karen complain " << std::endl;
}

void Karen::complain( std::string level)
{
    std::string   levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    func          complains[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
    
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*(complains[i]))();
            return ;
        }
    }
    std::cout << "[ Invalid ] level" << std::endl;
}