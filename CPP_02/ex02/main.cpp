#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    // Test constructors
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    // Test assignment operator
    a = Fixed(1234.4321f);

    // Output values using overloaded <<
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // Test toInt method
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // Test comparison operators
    std::cout << "c > b: " << (c > b) << std::endl;
    std::cout << "c < b: " << (c < b) << std::endl;
    std::cout << "c >= b: " << (c >= b) << std::endl;
    std::cout << "c <= b: " << (c <= b) << std::endl;
    std::cout << "c == b: " << (c == b) << std::endl;
    std::cout << "c != b: " << (c != b) << std::endl;

    // Test arithmetic operators
    Fixed result = c + b;
    std::cout << "c + b: " << result << std::endl;
    result = c - b;
    std::cout << "c - b: " << result << std::endl;
    result = c * b;
    std::cout << "c * b: " << result << std::endl;
    result = c / b;
    std::cout << "c / b: " << result << std::endl;

    // Edge case: Division by zero
    Fixed zero(0);
    std::cout << "Testing division by zero: ";
    try
    {
        std::cout << "c / zero: " << (c / zero) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: Division by zero" << std::endl;
    }

    // Test increment/decrement operators
    Fixed e;
    std::cout << "e: " << e << std::endl;
    std::cout << "++e: " << ++e << std::endl;
    std::cout << "e++: " << e++ << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "--e: " << --e << std::endl;
    std::cout << "e--: " << e-- << std::endl;
    std::cout << "e: " << e << std::endl;

    // Test min and max functions
    std::cout << "Max of c and b: " << Fixed::max(c, b) << std::endl;
    std::cout << "Min of c and b: " << Fixed::min(c, b) << std::endl;

    // Dynamic tests for min and max
    Fixed dynamic1(15.75f);
    Fixed dynamic2(3.14f);
    std::cout << "Max of dynamic1 and dynamic2: " << Fixed::max(dynamic1, dynamic2) << std::endl;
    std::cout << "Min of dynamic1 and dynamic2: " << Fixed::min(dynamic1, dynamic2) << std::endl;

    // Test edge values for arithmetic
    Fixed largeValue(1000000);
    Fixed smallValue(0.0001f);
    result = largeValue + smallValue;
    std::cout << "largeValue + smallValue: " << result << std::endl;
    result = largeValue - smallValue;
    std::cout << "largeValue - smallValue: " << result << std::endl;
    result = largeValue * smallValue;
    std::cout << "largeValue * smallValue: " << result << std::endl;

    return 0;
}
