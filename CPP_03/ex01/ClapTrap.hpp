#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected: // Changed to allow access in derived classes
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    static constexpr unsigned int c_hitPoints = 10;
    static constexpr unsigned int c_energyPoints = 10;
    static constexpr unsigned int c_attackDamagePoints = 0;

    // Constructors and Destructor
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    virtual ~ClapTrap(); // Destructor marked virtual

    // Assignment Operator
    ClapTrap &operator=(const ClapTrap &other);

    // Member Functions
    virtual void attack(const std::string &target); // Marked as virtual
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getters and Setters
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    void setAttackDamage(unsigned int value);
};

#endif // CLAPTRAP_HPP
