#include "FragTrap.hpp"
#include <iostream>

/**
 * @brief Default Constructor. Inheritance from ClapTrap
 */
FragTrap::FragTrap(void) : ClapTrap()
{
    this->_hitPoints = c_frag_hitPoints;
    this->_energyPoints = c_frag_energyPoints;
    this->_attackDamage = c_frag_attackDamagePoints;

    std::cout << "Frag-Trap with no name was constructed." << std::endl;
}

/**
 * @brief Construct by name. Inheritance from ClapTrap
 * @param name Name of the FragTrap
 */
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->_hitPoints = c_frag_hitPoints;
    this->_energyPoints = c_frag_energyPoints;
    this->_attackDamage = c_frag_attackDamagePoints;

    std::cout << "Frag-Trap named **" << name << " was constructed." << std::endl;
}

/**
 * @brief Copy Constructor. Inheritance from ClapTrap
 * @param src Object to copy
 */
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "Frag-Trap copy constructor called for **" << src._name << "." << std::endl;
}

/**
 * @brief Destructor
 */
FragTrap::~FragTrap(void)
{
    std::cout << "Frag-Trap **" << this->_name << " was destroyed." << std::endl;
}

/**
 * @brief Copy Assignment Operator
 * @param src Object to assign from
 */
FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src); // Delegate base class assignment
    }
    return *this;
}

/**
 * @brief Unique function for FragTrap
 */
void FragTrap::highFivesGuys(void)
{
    std::cout << "Frag-Trap **" << this->_name << " says: Let's High Five! ✋" << std::endl;
}
