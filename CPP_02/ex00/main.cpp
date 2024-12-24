// main.cpp
#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    // std::cout << "-------------------" << std::endl;
    // a.setRawBits(5);
    // std::cout << a.getRawBits() << std::endl;
    // std::cout << b.getRawBits() << std::endl;
    // b.setRawBits(10);
    // std::cout << c.getRawBits() << std::endl;

    return 0;
}