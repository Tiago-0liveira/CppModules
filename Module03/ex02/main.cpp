#include <FragTrap.hpp>

int main()
{
	FragTrap fragTrap("fragTrap");
	fragTrap.attack("Enemy");
	fragTrap.takeDamage(7);
	fragTrap.beRepaired(5);
	fragTrap.attack("Enemy");
	fragTrap.takeDamage(10);
	return 0;
}