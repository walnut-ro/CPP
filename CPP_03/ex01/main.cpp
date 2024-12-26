#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::string rb1 = "R-11";
    std::string rb2 = "A-99";

    ClapTrap ct1(rb1);
    ScavTrap ct2(rb2);

    // Test: Robot-01 attacks Android-02
    std::cout << "\nTest: " << rb1 << " Attack\n";
    ct1.setAttackDamage(1);
    ct1.attack(rb2);
    ct2.takeDamage(ct1.getAttackDamage());

    // Test: Android-02 attacks Robot-01
    std::cout << "\nTest: " << rb2 << " Attack\n";
    ct2.setAttackDamage(2);
    ct2.attack(rb1);
    ct1.takeDamage(ct2.getAttackDamage());

    // Test: Guard Gate
    std::cout << "\n\tGuardGate Test\n";
    ct2.guardGate();

    // Test: Zero Hit Points Guard Gate
    std::cout << "\n\tGuardGate Test with Zero Hit Points\n";
    ct2.takeDamage(100); // Reduce hit points to 0
    ct2.guardGate();

    // Test: Repairing all
    std::cout << "\nTest: Repaired all\n";
    ct1.beRepaired(2);
    ct2.beRepaired(1);

    std::cout << "\nEnd of simulation...\n";

    return 0;
}
