#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _raw;                            // Raw fixed-point value
    static const int _frac_nbr_bits = 8; // Number of fractional bits

public:
    // Constructors and Destructor
    Fixed(void);
    Fixed(Fixed const &src);
    ~Fixed(void);
    Fixed(int const n);
    Fixed(float const f);

    // Assignment Operator
    Fixed &operator=(Fixed const &src);

    // Getters and Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion Functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Overloaded << Operator
std::ostream &operator<<(std::ostream &os, const Fixed &number);

#endif // FIXED_HPP
