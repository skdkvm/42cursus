#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fx;
		static const int	bit = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int	getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif