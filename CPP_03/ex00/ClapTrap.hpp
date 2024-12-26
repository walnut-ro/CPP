#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string _name; // Name of the ClapTrap
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    // Static Constants for Default Values
    static constexpr int c_hitPoints = 10;
    static constexpr int c_energyPoints = 10;
    static constexpr int c_attackDamagePoints = 0;

    // Constructors and Destructor
    ClapTrap();                        // Default Constructor
    ClapTrap(const std::string &name); // Parameterized Constructor
    ClapTrap(const ClapTrap &other);   // Copy Constructor
    ~ClapTrap();                       // Destructor

    // Assignment Operator
    ClapTrap &operator=(const ClapTrap &other);

    // Public Member Functions
    void attack(const std::string &target); // Perform an attack
    void takeDamage(unsigned int amount);   // Take damage
    void beRepaired(unsigned int amount);   // Repair the ClapTrap

    // Getters
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;

    // Setters
    void setAttackDamage(unsigned int value);
};

#endif // CLAPTRAP_HPP
