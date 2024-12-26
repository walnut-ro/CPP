#include "Dog.hpp"
#include <iostream>

/**
 * @brief Default Constructor
 */
Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog constructor Called" << std::endl;
}

/**
 * @brief Copy Constructor
 */
Dog::Dog(Dog const &src) : Animal(src)
{
    std::cout << "Dog - Copy constructor called." << std::endl;
    this->_brain = new Brain(*src._brain); // Deep copy of Brain
}

/**
 * @brief Destructor
 */
Dog::~Dog(void)
{
    delete this->_brain; // Free the allocated memory
    std::cout << "Dog - Destructor called." << std::endl;
}

/**
 * @brief Copy Assignment Operator
 */
Dog &Dog::operator=(Dog const &src)
{
    if (this != &src)
    {
        Animal::operator=(src); // Assign base class attributes
        if (this->_brain)
            delete this->_brain;               // Free old memory
        this->_brain = new Brain(*src._brain); // Deep copy
    }
    std::cout << "Dog - Copy assignment operator called." << std::endl;
    return (*this);
}

/**
 * @brief Override MakeSound
 */
void Dog::makeSound(void) const
{
    std::cout << "Dog: Woof Woof!" << std::endl;
}
