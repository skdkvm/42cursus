/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:35:42 by seonggki          #+#    #+#             */
/*   Updated: 2022/01/16 17:48:02 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
static void	Help(void)
{
	std::cout << "Use ADD phonebook" << std::endl;
	std::cout << "Use SEARCH phonebook" << std::endl;
	std::cout << "Use EXIT to quit." << std::endl;
}

int	main(void)
{
	Phonebook	phonebook; 
	std::string	input;
	
	Help();
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
		{
			std::cout << "ADD START" << std::endl;
			phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			std::cout << "SEARCH START" << std::endl;
			phonebook.searchContact();
		}
		else if (input == "EXIT")
		{
			std::cout << "Good Bye" << std::endl;
			return (0);
		}
		else
			std::cout << "INVALID COMMAND" << std::endl;
	}
	return (0);
}