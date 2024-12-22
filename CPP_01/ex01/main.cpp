#include <iostream>
#include <limits>
#include <string>
#include "Zombie.hpp"

#define MAX_HORDE 10000
#define MIN_HORDE 1

Zombie *zombieHorde(int N, std::string name);

/**
 * @brief Get the number of Horde. Limited by previous definition and handle
 * not numeric input
 * @return int
 */
int handleZombieNumber()
{
    int hordeSize = 0;

    std::cout << "Enter the number of Zombies in the Horde: " << std::endl
              << "> ";
    while (!(std::cin >> hordeSize) || (hordeSize < MIN_HORDE || hordeSize > MAX_HORDE))
    {
        std::cout << "Invalid input. Please enter a number between " << MIN_HORDE << " and " << MAX_HORDE << "." << std::endl;
        std::cout << "> ";

        std::cin.clear();                                                   // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }
    return hordeSize;
}

/**
 * @brief Get a Horde name
 * @return string
 */
std::string getHordeName(void)
{
    std::string name;

    do
    {
        std::cout << "Give a name to your squad:" << std::endl
                  << "> ";
        std::getline(std::cin, name);

        if (name.empty())
        {
            std::cout << "Name cannot be empty. Try again." << std::endl;
        }
    } while (name.empty());

    return name;
}

int main(void)
{
    int hordeSize = handleZombieNumber();
    std::string hordeName = getHordeName();

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Summoning the Horde of " << hordeSize << " Zombies..." << std::endl;

    Zombie *zombies = zombieHorde(hordeSize, hordeName);

    for (int i = 0; i < hordeSize; i++)
    {
        zombies[i].announce();
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Return to your graves, Zombies!" << std::endl;

    delete[] zombies; // Free the allocated memory
    return 0;
}
