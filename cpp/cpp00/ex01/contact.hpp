/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:40:39 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/16 17:52:12 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    private:
            int         i;
            std::string first_name;
            std::string last_name;
            std::string nick_name;
            std::string phone_number;
            std::string secret;

    public:
            Contact();
            ~Contact();
                void    fillContact(int index);
                void    displayContact(void) const;
                void    displayContactDetails(void) const;
};


#endif
