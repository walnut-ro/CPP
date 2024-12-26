#include "Cat.hpp"
#include <iostream>

/**
 * @brief Default Constructor
 */
Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat constructor Called" << std::endl;
}

/**
 * @brief Copy Constructor
 */
Cat::Cat(Cat const &src) : Animal(src)
{
    std::cout << "Cat - Copy constructor called." << std::endl;
    this->_brain = new Brain(*src._brain); // Deep copy of Brain
}

/**
 * @brief Destructor
 */
Cat::~Cat(void)
{
    delete this->_brain; // Free the allocated memory
    std::cout << "Cat - Destructor called." << std::endl;
}

/**
 * @brief Copy Assignment Operator
 */
Cat &Cat::operator=(Cat const &src)
{
    if (this != &src)
    {
        Animal::operator=(src); // Assign base class attributes
        if (this->_brain)
            delete this->_brain;               // Free old memory
        this->_brain = new Brain(*src._brain); // Deep copy
    }
    std::cout << "Cat - Copy assignment operator called." << std::endl;
    return (*this);
}

/**
 * @brief Override MakeSound
 */
void Cat::makeSound(void) const
{
    std::cout << "Cat: Meow Meow!" << std::endl;
}

/**
 * @brief Getter for Brain
 * @return Pointer to the Brain object
 */
Brain *Cat::getBrain(void) const
{
    return this->_brain;
}
