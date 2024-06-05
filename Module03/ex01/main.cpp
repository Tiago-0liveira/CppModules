#include <ScavTrap.hpp>

int main()
{
	ScavTrap claptrap("Claptrap");
	claptrap.attack("Enemy");
	claptrap.takeDamage(7);
	claptrap.beRepaired(5);
	claptrap.attack("Enemy");
	claptrap.takeDamage(10);
	return 0;
}