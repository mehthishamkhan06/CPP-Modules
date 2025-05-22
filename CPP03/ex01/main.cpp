#include <iostream>
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Guardian");

    scav.attack("Bandit");

    scav.guardGate();  // test gatekeeper mode activation
    scav.guardGate();  // test calling it again

    return 0;
}
