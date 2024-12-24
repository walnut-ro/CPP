#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/******************************************************************************/
// Constructors and Destructor
/******************************************************************************/
Fixed::Fixed(void) : _raw(0) {}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

Fixed::Fixed(int const n) : _raw(n << _frac_nbr_bits) {}

Fixed::Fixed(float const f) : _raw(roundf(f * (1 << _frac_nbr_bits))) {}

Fixed::~Fixed(void) {}

/******************************************************************************/
// Copy Assignment Operator
/******************************************************************************/
Fixed &Fixed::operator=(Fixed const &src)
{
    if (this != &src)
    {
        this->_raw = src.getRawBits();
    }
    return *this;
}

/******************************************************************************/
// Comparison Operators
/******************************************************************************/
bool Fixed::operator>(const Fixed &value) const { return this->_raw > value._raw; }
bool Fixed::operator<(const Fixed &value) const { return this->_raw < value._raw; }
bool Fixed::operator>=(const Fixed &value) const { return this->_raw >= value._raw; }
bool Fixed::operator<=(const Fixed &value) const { return this->_raw <= value._raw; }
bool Fixed::operator==(const Fixed &value) const { return this->_raw == value._raw; }
bool Fixed::operator!=(const Fixed &value) const { return this->_raw != value._raw; }

/******************************************************************************/
// Arithmetic Operators
/******************************************************************************/
Fixed Fixed::operator+(const Fixed &value) const { return Fixed(this->toFloat() + value.toFloat()); }
Fixed Fixed::operator-(const Fixed &value) const { return Fixed(this->toFloat() - value.toFloat()); }
Fixed Fixed::operator*(const Fixed &value) const { return Fixed(this->toFloat() * value.toFloat()); }
Fixed Fixed::operator/(const Fixed &value) const
{
    if (value._raw == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / value.toFloat());
}

/******************************************************************************/
// Increment/Decrement Operators
/******************************************************************************/
Fixed Fixed::operator++(void)
{
    this->_raw += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed Fixed::operator--(void)
{
    this->_raw -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

/******************************************************************************/
// Static Member Functions
/******************************************************************************/
Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
    return (obj1.getRawBits() > obj2.getRawBits()) ? obj1 : obj2;
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
    return (obj1.getRawBits() < obj2.getRawBits()) ? obj1 : obj2;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    return (obj1.getRawBits() > obj2.getRawBits()) ? obj1 : obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    return (obj1.getRawBits() < obj2.getRawBits()) ? obj1 : obj2;
}

/******************************************************************************/
// Getters and Conversion Functions
/******************************************************************************/
int Fixed::getRawBits(void) const { return this->_raw; }

void Fixed::setRawBits(int const raw) { this->_raw = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(this->_raw) / (1 << _frac_nbr_bits); }

int Fixed::toInt(void) const { return this->_raw >> _frac_nbr_bits; }

/******************************************************************************/
// Overloaded << Operator
/******************************************************************************/
std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
    os << number.toFloat();
    return os;
}
