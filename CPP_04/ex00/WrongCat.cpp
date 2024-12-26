#include "WrongCat.hpp"
#include <iostream>

/**
 * @brief Default Constructor
 */
WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
    std::cout << "WrongCat constructor Called" << std::endl;
    this->_type = "WrongCat";
}

/**
 * @brief Copy constructor
 */
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src._type)
{
    std::cout << "WrongCat - Copy constructor called." << std::endl;
    *this = src;
}

/**
 * @brief Destructor
 */
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat - Destructor called." << std::endl;
}

/**
 * @brief Copy assignment operator
 */
WrongCat &WrongCat::operator=(WrongCat const &src)
{
    if (this != &src)
    {
        this->_type = src.getType();
    }
    std::cout << "WrongCat - Copy assignment operator called." << std::endl;
    return (*this);
}

/**
 * @brief Member function - Make Sound
 */
void WrongCat::makeSound(void) const
{
    std::cout << this->_type << ": Meooow meoooowwwwwwww" << std::endl;
}
