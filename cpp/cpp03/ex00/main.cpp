#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap p1("one");
	ClapTrap p2("two");
	ClapTrap p3;
	
	p3 = p1;
	p2.attack("random target");
	p2.takeDamage(50);
	p2.takeDamage(3);
	p2.beRecaired(10);
	p2.takeDamage(30);
	p1.takeDamage(5);
	p1.takeDamage(3);
	p1.beRecaired(10);
	p1.takeDamage(30);
	
	return (0);
}