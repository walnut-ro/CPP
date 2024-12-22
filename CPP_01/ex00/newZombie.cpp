#include "Zombie.hpp"

/**
 * @brief It creates a zombie, name it, and return it so you can use it outside
 * of the function scope
 * @param name
 * @return Zombie*
 */
Zombie *newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return (zombie);
}