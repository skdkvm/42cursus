/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:40:51 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/16 17:35:17 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"
# define maxContacts 8

class Phonebook
{
    private:
            int     num_of_contact;
            Contact contacts[maxContacts];

    public:
            Phonebook();
            ~Phonebook();
            void    addContact(void);
            void    searchContact(void) const;
};
#endif