#include "Cat.hpp"
#include <string>
#include <iostream>

/**
 * @brief Default Constructor
 */
Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor Called" << std::endl;
    this->_type = "Cat";
}

/**
 * @brief Copy constructor
 */
Cat::Cat(Cat const &src) : Animal(src._type)
{
    std::cout << "Cat - Copy constructor called." << std::endl;
    *this = src;
}

/**
 * @brief Destructor
 */
Cat::~Cat(void)
{
    std::cout << "Cat - Destructor called." << std::endl;
}

/**
 * @brief Copy assignment operator
 */
Cat &Cat::operator=(Cat const &src)
{
    if (this != &src)
    {
        this->_type = src.getType();
    }
    std::cout << "Cat - Copy assignment operator called." << std::endl;
    return (*this);
}

/**
 * @brief Member function - Make Sound
 */
void Cat::makeSound(void) const
{
    std::cout << this->_type << ": Meooow meoooowwwwwwww" << std::endl;
}
