#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;/* Using copy assignment operator */
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_fixedPointValue = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}