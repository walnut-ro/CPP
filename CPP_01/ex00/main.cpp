#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    // Heap Allocation
    Zombie *firstZombie = newZombie("Z1");
    firstZombie->announce();
    delete firstZombie;

    // Stack allocation
    randomChump("Z2");
    return (0);
}