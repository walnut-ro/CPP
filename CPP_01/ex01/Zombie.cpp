#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() : _name("")
{
    std::cout << "A zombie respawn!" << std::endl;
}

// Parameterized constructor
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "The zombie '" << this->_name << "' respawn!" << std::endl;
}

// Destructor
Zombie::~Zombie()
{
    std::cout << "The zombie '" << this->_name << "' is destroyed." << std::endl;
}

// Setter for name
void Zombie::setName(const std::string &name)
{
    this->_name = name;
}

// Announce
void Zombie::announce(void) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
