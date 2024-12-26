#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::string rb1 = "R-00";
    std::string rb2 = "A-55";

    // Create ClapTrap instances
    ClapTrap ct1(rb1);
    ClapTrap ct2(rb2);

    // Test: Robot-01 attacks Android-02
    std::cout << "\nTest: " << rb1 << " Attack" << std::endl;
    ct1.setAttackDamage(1);
    ct1.attack(rb2);
    ct2.takeDamage(ct1.getAttackDamage());

    // Display status
    std::cout << rb1 << " - Hit Points: " << ct1.getHitPoints() << ", Energy Points: " << ct1.getEnergyPoints() << std::endl;
    std::cout << rb2 << " - Hit Points: " << ct2.getHitPoints() << ", Energy Points: " << ct2.getEnergyPoints() << std::endl;

    // Test: Android-02 attacks Robot-01
    std::cout << "\nTest: " << rb2 << " Attack" << std::endl;
    ct2.setAttackDamage(2);
    ct2.attack(rb1);
    ct1.takeDamage(ct2.getAttackDamage());

    // Display status
    std::cout << rb1 << " - Hit Points: " << ct1.getHitPoints() << ", Energy Points: " << ct1.getEnergyPoints() << std::endl;
    std::cout << rb2 << " - Hit Points: " << ct2.getHitPoints() << ", Energy Points: " << ct2.getEnergyPoints() << std::endl;

    // Test: Both ClapTraps repair themselves
    std::cout << "\nTest: Repaired all" << std::endl;
    ct1.beRepaired(2);
    ct2.beRepaired(1);

    // Display final status
    std::cout << rb1 << " - Hit Points: " << ct1.getHitPoints() << ", Energy Points: " << ct1.getEnergyPoints() << std::endl;
    std::cout << rb2 << " - Hit Points: " << ct2.getHitPoints() << ", Energy Points: " << ct2.getEnergyPoints() << std::endl;

    std::cout << "\nEnd of simulation..." << std::endl;
    return 0;
}
