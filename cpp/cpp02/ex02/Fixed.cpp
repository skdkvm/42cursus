#include "Fixed.hpp"

Fixed::Fixed() : fx(0)
{
	return ;
}

Fixed::Fixed(int num)
{
	fx = num << bit;
}

Fixed::Fixed(float fnum)
{
	fx = ((int)roundf(fnum * (1 << bit)));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	setRawBits(fixed.getRawBits());
	return *this;
}
//비교 연산자
bool	Fixed::operator>(const Fixed &fixed) const
{
	return this->fx > fixed.fx;
}
bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->fx < fixed.fx;
}
bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->fx >= fixed.fx;
}
bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->fx <= fixed.fx;
}
bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->fx == fixed.fx;
}
bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->fx != fixed.fx;
}
//산술 연산자
Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}
Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}
Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}
Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}
//증감 연산자
Fixed	&Fixed::operator++(void)
{
	++(this->fx);
	return (*this);
}
Fixed	&Fixed::operator--(void)
{
	--(this->fx);
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++(this->fx);
	return (temp);
}
Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--(this->fx);
	return (temp);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed2;
	else
		return fixed1;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed2;
	else
		return fixed1;
}

const Fixed	&Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed2;
	else
		return fixed1;
}
const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return fixed2;
	else
		return fixed1;
}

Fixed::~Fixed()
{
	
}

int		Fixed::getRawBits(void) const
{
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
