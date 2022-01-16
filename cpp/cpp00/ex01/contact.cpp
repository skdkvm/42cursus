/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:40:34 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/16 17:53:00 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

void    Contact::fillContact(int index)
{
    i = index;
    std::cout << "fill the informations." << std::endl;
    std::cout << std::setw(17) << "First name  ";
    std::getline(std::cin, first_name);
    std::cout << std::setw(17) << "Last name  ";
    std::getline(std::cin, last_name);
    std::cout << std::setw(17) << "Nick name  ";
    std::getline(std::cin, nick_name);
    std::cout << std::setw(17) << "Phone number  ";
    std::getline(std::cin, phone_number);
    std::cout << std::setw(17) << "Secret  ";
    std::getline(std::cin, secret);
}

static void printTenChar(std::string str)
{
    int         len;
    std::string spaces(10, ' ');

    len = str.length();
    if (len <= 10)
        std::cout << spaces.substr(0, 10 - len) << str;
    else
        std::cout << str.substr(0, 9) << '.';
}

void    Contact::displayContact(void) const
{
    printTenChar(std::to_string(i));
    std::cout << "|";
    printTenChar(first_name);
    std::cout << "|";
    printTenChar(last_name);
    std::cout << "|";
    printTenChar(nick_name);
    std::cout << std::endl;
}

void    Contact::displayContactDetails(void) const
{
    std::cout << std::setw(17) << "First name " << first_name << std :: endl;
    std::cout << std::setw(17) << "Last name " << last_name << std :: endl;
    std::cout << std::setw(17) << "Nick name " << nick_name << std :: endl;
    std::cout << std::setw(17) << "Phone number " << phone_number << std :: endl;
    std::cout << std::setw(17) << "Secret " << secret << std :: endl;
}