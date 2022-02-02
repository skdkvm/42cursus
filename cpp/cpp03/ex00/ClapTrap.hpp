#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	name;
		int			HP;
		int			EP;
		int			AD;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
	
		~ClapTrap();
	
		ClapTrap &operator=(const ClapTrap &claptrap);
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRecaired(unsigned int amount);
};

#endif