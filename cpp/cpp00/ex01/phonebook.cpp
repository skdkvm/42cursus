/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:41:06 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/27 16:57:39 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    num_of_contact = -1;
    return ;
}
Phonebook::~Phonebook(void)
{
    return ;
}

void    Phonebook::addContact(void)
{
    if (num_of_contact >= maxContacts - 1)
            contacts[0].fillContact(0);
    else
    {
        num_of_contact++;
        contacts[num_of_contact].fillContact(num_of_contact);
    }
    std::cout << std::setw(17) << "FillContact OK" << std::endl;
}

static void     displayHeader(void)
{
    std::string     header;
    std::string     line(44, '-');

    header += "     Index|";
    header += "First Name|";
    header += "Last Name |";
    header += "Nick name |";
    std::cout << header << std::endl << line << std::endl;
}

void    Phonebook::searchContact(void) const
{
    int         i;
    int         index;
    std::string index_str;

    if (num_of_contact == -1)
    {
        std::cout << "Is Empty" << std::endl << std::endl;
        return ;
    }
    displayHeader();
    i = -1;
    while (++i <= num_of_contact)
        contacts[i].displayContact();
    std::cout << std::endl;
    index = -1;
    while (index < 0 || index > num_of_contact)
    {
        std::cout << "Enter a valid index ";
        std::getline(std::cin, index_str);
        index = std::stoi(index_str);
    }
    contacts[index].displayContactDetails();
    std::cout << std::endl;
}