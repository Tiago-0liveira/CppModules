#include "Fixed.hpp"

Fixed::Fixed() {
	this->_fixedPointValue = 0;
}
Fixed::~Fixed() {}
Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	if (this == &copy)
		return (*this);
	this->_fixedPointValue = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return this->_fixedPointValue;
}
void Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int value)
{
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat( void ) const
{
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

bool Fixed::operator>(const Fixed &fixed) const {
	return (this->_fixedPointValue > fixed.getRawBits());
}
bool Fixed::operator<(const Fixed &fixed) const {
	return (this->_fixedPointValue < fixed.getRawBits());
}
bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->_fixedPointValue >= fixed.getRawBits());
}
bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->_fixedPointValue <= fixed.getRawBits());
}
bool Fixed::operator==(const Fixed &fixed) const {
	return (this->_fixedPointValue == fixed.getRawBits());
}
bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->_fixedPointValue != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}
Fixed Fixed::operator-(const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed Fixed::operator*(const Fixed &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed Fixed::operator/(const Fixed &fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
	setRawBits(this->_fixedPointValue + 1);
	return *this;
}
Fixed &Fixed::operator--(void) {
	setRawBits(this->_fixedPointValue - 1);
	return *this;
}
Fixed	Fixed::operator++(int value)
{
	Fixed	tmp;
	tmp = *this;
	if (!value) value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (tmp);
}

Fixed	Fixed::operator--(int value)
{
	Fixed	tmp;
	tmp = *this;
	if (!value) value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}
Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}