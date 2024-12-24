// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedValue;                      // To store the fixed-point value
    static const int _fractionalBits = 8; // Number of fractional bits (always 8)

public:
    // Default constructor
    Fixed();

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed &operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    // Getter for the raw bits
    int getRawBits(void) const;

    // Setter for the raw bits
    void setRawBits(int const raw);
};

#endif // FIXED_HPP
