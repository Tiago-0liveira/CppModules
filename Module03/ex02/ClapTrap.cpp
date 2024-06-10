#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = "default";
	_hitpoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = name;
	_hitpoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const& src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}
ClapTrap &ClapTrap::operator=(ClapTrap const& rhs) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(std::string const& target) {
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	} else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitpoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
		return;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy and can't be repaired!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points of damage!" << std::endl;
	_hitpoints += amount;
}