#include "Fixed.hpp"

Fixed::Fixed() : fx(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	fx = num << bit;
}

Fixed::Fixed(float fnum)
{
	std::cout << "Float constructor called" << std::endl;
	fx = ((int)roundf(fnum * (1 << bit)));
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

float 	Fixed::toFloat( void ) const
{
	return ((float)fx / (1 << bit));
}

int 	Fixed::toInt( void ) const
{
	return ((int)fx / (1 << bit));
}

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}
