#include "DerivedClasses.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base *generate()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    if (r == 1)
        return new B;
    return new C;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << "Not A: " << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << "Not B: " << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << "Not C: " << e.what() << std::endl;
    }
    std::cout << "Unknown type" << std::endl;
}