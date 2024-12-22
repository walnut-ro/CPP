#include "Zombie.hpp"

/**
 * @brief It creates a zombie, name it, and the zombie announces itself.
 * @param name
 */
void randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
    return;
}