#include <ScavTrap.hpp>

int main()
{
	ScavTrap scavTrap("Claptrap");
	scavTrap.attack("Enemy");
	scavTrap.takeDamage(7);
	scavTrap.beRepaired(5);
	scavTrap.attack("Enemy");
	scavTrap.takeDamage(10);
	scavTrap.guardGate();
	return 0;
}