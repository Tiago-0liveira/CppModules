#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	ClapTrap(ClapTrap const & src);
	ClapTrap &operator=(ClapTrap const & rhs);
	
	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	std::string _name;
	int _hitpoints;
	int _energyPoints;
	int _attackDamage;
};

#endif //CLAPTRAP_HPP
