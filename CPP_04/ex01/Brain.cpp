#include "Brain.hpp"
#include <string>
#include <iostream>

/**
 * @brief Default Constructor
 */
Brain::Brain(void)
{
    std::cout << "Brain constructor Called" << std::endl;
}

/**
 * @brief Copy constructor
 */
Brain::Brain(Brain const &src)
{
    std::cout << "Brain - Copy constructor called." << std::endl;
    *this = src;
}

/**
 * @brief Destructor
 */
Brain::~Brain(void)
{
    std::cout << "Brain - Destructor called." << std::endl;
}

/**
 * @brief Copy assignment operator.
 * Responsible to pass value of all Ideas in Brain animals
 */
Brain &Brain::operator=(Brain const &src)
{
    if (this != &src)
    {
        for (int i = 0; i < BRAIN_SIZE; i++)
            this->_ideas[i] = src._ideas[i];
    }
    return (*this);
}

/**
 * @brief Get an idea from a specific index.
 *
 * @param index Index of the idea
 * @return std::string The idea at the given index, or empty if out of bounds
 */
std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= BRAIN_SIZE)
    {
        return "";
    }
    return this->_ideas[index];
}

/**
 * @brief Set an idea at a specific index.
 *
 * @param index Index to set the idea
 * @param idea The idea to set
 */
void Brain::setIdea(int index, std::string const &idea)
{
    if (index >= 0 && index < BRAIN_SIZE)
        this->_ideas[index] = idea;
}
