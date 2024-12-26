#include "ClapTrap.hpp"
#include <iostream>

/**
 * @brief Default Constructor
 */
ClapTrap::ClapTrap(void) : _name("unnamed"),
                           _hitPoints(c_hitPoints),
                           _energyPoints(c_energyPoints),
                           _attackDamage(c_attackDamagePoints)
{
    std::cout << "Cl4p-tp with no name was constructed" << std::endl;
}

/**
 * @brief Parameterized Constructor
 * @param name Name of the ClapTrap
 */
ClapTrap::ClapTrap(const std::string &name) : _name(name),
                                              _hitPoints(c_hitPoints),
                                              _energyPoints(c_energyPoints),
                                              _attackDamage(c_attackDamagePoints)
{
    std::cout << "Cl4p-tp named **" << name << " was constructed" << std::endl;
}

/**
 * @brief Copy Constructor
 * @param src Object to copy
 */
ClapTrap::ClapTrap(const ClapTrap &src) : _name(src._name),
                                          _hitPoints(src._hitPoints),
                                          _energyPoints(src._energyPoints),
                                          _attackDamage(src._attackDamage)
{
    std::cout << "Copy constructor called." << std::endl;
}

/**
 * @brief Destructor
 */
ClapTrap::~ClapTrap(void)
{
    std::cout << "Cl4p-tp **" << _name << " destroyed" << std::endl;
}

/**
 * @brief Copy Assignment Operator
 * @param src Object to assign from
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
    {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

/* Getter and Setter Methods */
std::string ClapTrap::getName(void) const { return _name; }
unsigned int ClapTrap::getHitPoints(void) const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints(void) const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }
void ClapTrap::setAttackDamage(unsigned int value) { _attackDamage = value; }

/**
 * @brief Perform an attack
 * @param target Target to attack
 */
void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints == 0)
    {
        std::cout << "Cl4p-tp **" << _name << " has no hit points left and cannot attack." << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "Cl4p-tp **" << _name << " has no energy points left and cannot attack." << std::endl;
        return;
    }
    if (_attackDamage == 0)
    {
        std::cout << "Cl4p-tp **" << _name << " tried to attack but caused no damage!" << std::endl;
        return;
    }

    _energyPoints--;
    std::cout << "Cl4p-tp **" << _name << " attacks **" << target
              << ", causing " << _attackDamage << " points of damage! Energy remaining: "
              << _energyPoints << "." << std::endl;
}

/**
 * @brief Take damage
 * @param amount Amount of damage to take
 */
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "Cl4p-tp **" << _name << " cannot take more damage, it has no hit points left." << std::endl;
        return;
    }

    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
    }
    else
    {
        _hitPoints -= amount;
    }

    std::cout << "Cl4p-tp **" << _name << " takes " << amount
              << " damage. Hit points remaining: " << _hitPoints << "." << std::endl;
}

/**
 * @brief Repair the ClapTrap
 * @param amount Amount of hit points to repair
 */
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "Cl4p-tp **" << _name << " cannot repair because it has no hit points left." << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "Cl4p-tp **" << _name << " cannot repair because it has no energy points left." << std::endl;
        return;
    }
    if (amount == 0)
    {
        std::cout << "Invalid repair amount: 0. No changes made to hit points." << std::endl;
        return;
    }

    _energyPoints--;

    if (_hitPoints + amount > c_hitPoints)
    {
        _hitPoints = c_hitPoints; // Cap to maximum hit points
    }
    else
    {
        _hitPoints += amount;
    }

    std::cout << "Cl4p-tp **" << _name << " repairs for " << amount
              << ". Hit points: " << _hitPoints << ", energy points: " << _energyPoints << "." << std::endl;
}
