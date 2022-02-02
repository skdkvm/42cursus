#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fx;
		static const int	bit = 8;
	
	public:
		Fixed();
		Fixed(int num);
		Fixed(float fnum);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void 	setRawBits(const int raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif