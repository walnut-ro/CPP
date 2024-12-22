#include "Zombie.hpp"

/**
 * @brief Create a Horde of zombies
 * @param N Number of zombies
 * @param name Name of squad
 * @return Zombie*
 */
Zombie *zombieHorde(int N, std::string name)
{
    if (N < 1)
    {
        return nullptr;
    }

    // Allocate memory for the horde
    Zombie *horde = new Zombie[N];

    // Initialize each zombie in the horde
    for (int i = 0; i < N; ++i)
    {
        horde[i].setName(name + "_" + std::to_string(i + 1));
    }

    return horde;
}
