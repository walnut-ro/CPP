#include "Animal.hpp"
#include <string>
#include <iostream>

/**
 * @brief Default Constructor - Initializes type to "undefined".
 */
Animal::Animal(void) : _type("undefined")
{
    std::cout << "Animal - No Param Constructor Called" << std::endl;
}

/**
 * @brief Copy Constructor - Copies attributes from another Animal.
 * @param src Source Animal object.
 */
Animal::Animal(Animal const &src)
{
    std::cout << "Animal - Copy Constructor Called." << std::endl;
    *this = src;
}

/**
 * @brief Parameterized Constructor - Initializes type with a given value.
 * @param type The type of the animal.
 */
Animal::Animal(std::string const &type) : _type(type)
{
    std::cout << "Animal - Type Constructor Called" << std::endl;
}

/**
 * @brief Destructor - Called when the object is destroyed.
 */
Animal::~Animal(void)
{
    std::cout << "Animal - Destructor Called." << std::endl;
}

/**
 * @brief Copy Assignment Operator - Copies attributes from another Animal.
 * @param src Source Animal object.
 * @return Reference to the current object.
 */
Animal &Animal::operator=(Animal const &src)
{
    if (this != &src)
    {
        this->_type = src.getType();
    }
    std::cout << "Animal - Copy Assignment Operator Called." << std::endl;
    return (*this);
}

/**
 * @brief Get the type of the animal.
 * @return The type as a std::string.
 */
std::string Animal::getType(void) const
{
    return (this->_type);
}

/**
 * @brief Produces a generic sound for the base Animal class.
 */
void Animal::makeSound(void) const
{
    std::cout << this->_type << ": No one knows this sound!" << std::endl;
}
