#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

/**
 * @brief Default Constructor
 */
WrongAnimal::WrongAnimal(void) : _type("undefined")
{
    std::cout << "WrongAnimal - No Param Constructor Called" << std::endl;
}

/**
 * @brief Copy constructor
 */
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "WrongAnimal - Copy constructor called." << std::endl;
    *this = src;
}

/**
 * @brief Default constructor with one param
 * @param type of animal
 */
WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
    std::cout << "WrongAnimal - Type animal Constructor Called" << std::endl;
}

/**
 * @brief Destructor
 */
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal - Destructor called." << std::endl;
}

/**
 * @brief Copy assignment operator
 */
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
    if (this != &src)
    {
        this->_type = src.getType();
    }
    std::cout << "WrongAnimal - Copy assignment operator called." << std::endl;
    return (*this);
}

/**
 * @brief Get Type of animal
 * @return std::string
 */
std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

/**
 * @brief Member Function - MakeSound
 */
void WrongAnimal::makeSound(void) const
{
    std::cout << this->_type << ": No one knows this sound!" << std::endl;
}
