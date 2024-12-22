#include "Zombie.hpp"
#include <string>
#include <iostream>

/**
 * @brief Constructor
 */
Zombie::Zombie(void)
{
    std::cout << "A zombie respawn!" << std::endl;
    return;
}

/**
 * @brief Construct a new Zombie: name by param
 * @param name
 */
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "The zombie '" << this->getName() << "' respawn!" << std::endl;
    return;
}

/**
 * @brief Destructor
 */
Zombie::~Zombie(void)
{
    std::cout << "The zombie '" << this->_name << "' is destroyed." << std::endl;
    return;
}

/**
 * @brief Getter - Get Name
 * @return std::string
 */
std::string Zombie::getName(void) const
{
    return (this->_name);
}

/**
 * @brief Zombie announce itself
 */
void Zombie::announce(void)
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}