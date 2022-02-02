#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
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
		Fixed	&operator=(const Fixed &fixed);
		//비교 연산자(>, <, >=, <=, ==, !=)
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		
		//산술 연산자(+, -, *, /)
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;
	
		//증감 연산자(전위 ,후위)
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		~Fixed();
		int		getRawBits(void) const;
		void 	setRawBits(const int raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
	
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&max(Fixed const &fixed1, Fixed const &fixed2);
		static const Fixed	&min(Fixed const &fixed1, Fixed const &fixed2);
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif