#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
    // Constructors and Destructor
    FragTrap(const std::string &name); // Parameterized Constructor
    FragTrap(const FragTrap &src);     // Copy Constructor
    ~FragTrap();                       // Destructor

    // Assignment Operator
    FragTrap &operator=(const FragTrap &src);

    // Unique Function
    void highFivesGuys();

    // Static Constants
    static constexpr int c_frag_hitPoints = 100;
    static constexpr int c_frag_energyPoints = 100;
    static constexpr int c_frag_attackDamagePoints = 30;

private:
    FragTrap(); // Private Default Constructor
};

#endif // FRAGTRAP_HPP
