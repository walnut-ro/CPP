#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Default Constructor
 */
Fixed::Fixed(void) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Copy constructor
 */
Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
}

/**
 * @brief Construct - Integer parameter
 * @param n
 */
Fixed::Fixed(int const n) : _raw(n << _frac_nbr_bits)
{
    std::cout << "Int constructor called." << std::endl;
}

/**
 * @brief Construct - Float parameter
 * @param f
 */
Fixed::Fixed(float const f) : _raw(roundf(f * (1 << _frac_nbr_bits)))
{
    std::cout << "Float constructor called." << std::endl;
}

/**
 * @brief Destructor
 */
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Copy assignment operator
 */
Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &src)
    {
        this->_raw = src.getRawBits();
    }
    return *this;
}

/**
 * @brief Getter
 * @return int
 */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return this->_raw;
}

/**
 * @brief Setter
 */
void Fixed::setRawBits(int const raw)
{
    std::cout << "SetRawBits called." << std::endl;
    this->_raw = raw;
}

/**
 * @brief To Float Function
 * Converts the fixed-point value to a floating-point value.
 * @return float
 */
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_raw) / (1 << _frac_nbr_bits);
}

/**
 * @brief To Int Function
 * Converts the fixed-point value to an integer value.
 * @return int
 */
int Fixed::toInt(void) const
{
    return this->_raw >> _frac_nbr_bits;
}

/**
 * @brief Overload of operator <<
 * @param os
 * @param number
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
    os << number.toFloat();
    return os;
}
