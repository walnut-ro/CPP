#include "Dog.hpp"
#include <iostream>

/**
 * @brief Default Constructor
 */
Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor Called" << std::endl;
    this->_type = "Dog";
}

/**
 * @brief Copy constructor
 */
Dog::Dog(Dog const &src) : Animal(src._type)
{
    std::cout << "Dog - Copy constructor called." << std::endl;
    *this = src;
}

/**
 * @brief Destructor
 */
Dog::~Dog(void)
{
    std::cout << "Dog - Destructor called." << std::endl;
}

/**
 * @brief Copy assignment operator
 */
Dog &Dog::operator=(Dog const &src)
{
    if (this != &src)
    {
        this->_type = src.getType();
    }
    std::cout << "Dog - Copy assignment operator called." << std::endl;
    return (*this);
}

/**
 * @brief Member function - Make Sound
 */
void Dog::makeSound(void) const
{
    std::cout << this->_type << ":  Au Au, Arf! Arf!" << std::endl;
}
