/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:31:22 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/29 16:54:25 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int error(void)
{
    std::cout << "Wrong number of arguments." << std::endl;
    return (1);
}

static  int     getLevel(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
                return (i);
    }
    return (4);
}

int main(int argc, char **argv)
{
    Karen       k;
    int         num;

    if (argc != 2)
        return (error());
    num = getLevel(argv[1]);
    switch (num)
    {
    case 0:
            k.complain("DEBUG");
    case 1:
            k.complain("INFO");
    case 2:
            k.complain("WARNING");
    case 3:
            k.complain("ERROR");
            break;
    default:
            std::cout << "Probably complaining about insignificant problems" << std::endl;
    }
    return (0);
}