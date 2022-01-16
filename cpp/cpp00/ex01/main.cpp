#include "phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook; 
	std::string	input;
	
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			return (0);
		else if (input == "SEARCH")
			return (0);
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "INVALID COMMAND\n";
	}
	return (0);
}