#include "ScavTrap.hpp"
#include <iostream>

/**
 * @brief Default Constructor. Inherits from ClapTrap
 */
ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_hitPoints = c_scav_hitPoints;
    this->_energyPoints = c_scav_energyPoints;
    this->_attackDamage = c_scav_attackDamagePoints;

    std::cout << "Sc4v-tp with no name was constructed." << std::endl;
}

/**
 * @brief Parameterized Constructor. Inherits from ClapTrap
 * @param name Name of the ScavTrap
 */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->_hitPoints = c_scav_hitPoints;
    this->_energyPoints = c_scav_energyPoints;
    this->_attackDamage = c_scav_attackDamagePoints;

    std::cout << "Sc4v-tp named **" << name << " was constructed." << std::endl;
}

/**
 * @brief Copy Constructor. Inherits from ClapTrap
 * @param src Object to copy from
 */
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "Sc4v-tp copy constructor called for **" << src._name << "." << std::endl;
}

/**
 * @brief Destructor
 */
ScavTrap::~ScavTrap(void)
{
    std::cout << "Sc4v-tp **" << this->_name << " was destroyed." << std::endl;
}

/**
 * @brief Copy Assignment Operator
 * @param src Object to assign from
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src); // Delegate base class assignment
    }
    return *this;
}

/**
 * @brief Attack function for ScavTrap. Overrides ClapTrap's attack
 * @param target Target of the attack
 */
void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "Sc4v-tp **" << this->_name << " has no hit points left to attack." << std::endl;
        return;
    }

    if (this->_energyPoints <= 0)
    {
        std::cout << "Sc4v-tp **" << this->_name << " has no energy points left to attack." << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "Sc4v-tp **" << this->_name << " attacks **" << target
              << ", causing " << this->_attackDamage << " points of damage! Energy remaining: "
              << this->_energyPoints << "." << std::endl;
}

/**
 * @brief Activate Gate Keeper Mode
 */
void ScavTrap::guardGate(void)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "Sc4v-tp **" << this->_name << " cannot guard the gate in its broken state." << std::endl;
    }
    else
    {
        std::cout << "Sc4v-tp **" << this->_name << " switches to Gate Keeper Mode!" << std::endl;
    }
}
