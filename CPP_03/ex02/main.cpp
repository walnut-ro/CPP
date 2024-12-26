#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::string rb1 = "R-333";
    std::string rb2 = "A-777";

    ClapTrap ct1(rb1);
    FragTrap ct2(rb2);

    // Test: R-333 attacks A-777
    std::cout << "\nTest: " << rb1 << " Attacks " << rb2 << "\n";
    ct1.setAttackDamage(1);
    ct1.attack(rb2);
    ct2.takeDamage(ct1.getAttackDamage());

    // Test: A-777 attacks R-333
    std::cout << "\nTest: " << rb2 << " Attacks " << rb1 << "\n";
    ct2.setAttackDamage(2);
    ct2.attack(rb1);
    ct1.takeDamage(ct2.getAttackDamage());

    // High Five Test
    std::cout << "\n\tHigh Five Test\n";
    ct2.highFivesGuys();

    // Repair Test
    std::cout << "\nTest: Repaired All\n";
    ct1.beRepaired(2);
    ct2.beRepaired(1);

    // Edge Case: Attack with 0 Energy
    std::cout << "\nTest: Attack with 0 Energy\n";
    std::cout << "Draining energy points for " << rb2 << "...\n";
    while (ct2.getEnergyPoints() > 0)
    {
        ct2.attack(rb1);
    }
    ct2.attack(rb1); // Attempt attack with no energy

    // Edge Case: Attack with 0 Hit Points
    std::cout << "\nTest: Attack with 0 Hit Points\n";
    ct2.takeDamage(100); // Reduce hit points to 0
    ct2.attack(rb1);     // Attempt attack with no hit points

    // Edge Case: Repair at Maximum Hit Points
    std::cout << "\nTest: Repair at Max Hit Points\n";
    ct1.beRepaired(5); // Attempt repair beyond max hit points

    std::cout << "\nEnd of simulation...\n";

    return 0;
}
