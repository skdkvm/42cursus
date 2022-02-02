#include "Fixed.hpp"

Fixed::Fixed() : fx(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called " << std::endl;
	setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fx;
}

void	Fixed::setRawBits(const int raw)
{
	fx = raw;
}