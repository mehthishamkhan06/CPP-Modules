#include <iostream>
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- ScavTrap Object Creation ---\n";
    ScavTrap scav("Guardian");
    std::cout << "\n--- Attack Test ---\n";
    scav.attack("Bandit");

    std::cout << "\n--- Gate Keeper Mode Activation (1st Call) ---\n";
    scav.guardGate();

    std::cout << "\n--- Gate Keeper Mode Activation (2nd Call) ---\n";
    scav.guardGate();

    return 0;
}
