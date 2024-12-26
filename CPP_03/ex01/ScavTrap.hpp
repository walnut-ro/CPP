#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
    // Constructors and Destructor
    ScavTrap(const std::string &name); // Parameterized Constructor
    ScavTrap(const ScavTrap &src);     // Copy Constructor
    ~ScavTrap();                       // Destructor

    // Assignment Operator
    ScavTrap &operator=(const ScavTrap &src);

    // Member Functions
    void attack(const std::string &target) override; // Override ClapTrap's attack
    void guardGate();                                // Unique to ScavTrap

    // Static Constants
    static constexpr int c_scav_hitPoints = 100;
    static constexpr int c_scav_energyPoints = 50;
    static constexpr int c_scav_attackDamagePoints = 20;

private:
    // Private Default Constructor
    ScavTrap();
};

#endif // SCAVTRAP_HPP
