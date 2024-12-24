#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    int _raw;                            // Raw fixed-point value
    static const int _frac_nbr_bits = 8; // Number of fractional bits

public:
    // Constructors and Destructor
    Fixed(void);
    Fixed(const Fixed &src);
    ~Fixed(void);
    Fixed(int const n);
    Fixed(float const f);

    // Assignment Operator
    Fixed &operator=(const Fixed &src);

    // Comparison Operators (const)
    bool operator>(const Fixed &value) const;
    bool operator<(const Fixed &value) const;
    bool operator>=(const Fixed &value) const;
    bool operator<=(const Fixed &value) const;
    bool operator==(const Fixed &value) const;
    bool operator!=(const Fixed &value) const;

    // Arithmetic Operators (const)
    Fixed operator+(const Fixed &value) const;
    Fixed operator-(const Fixed &value) const;
    Fixed operator/(const Fixed &value) const;
    Fixed operator*(const Fixed &value) const;

    // Increment/Decrement Operators
    Fixed operator++(void); // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed operator--(void); // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    // Static Member Functions
    static Fixed &max(Fixed &obj1, Fixed &obj2);
    static Fixed &min(Fixed &obj1, Fixed &obj2);
    static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
    static const Fixed &min(const Fixed &obj1, const Fixed &obj2);

    // Getter and Setter
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion Functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Overloaded << Operator
std::ostream &operator<<(std::ostream &os, const Fixed &number);

#endif // FIXED_H
