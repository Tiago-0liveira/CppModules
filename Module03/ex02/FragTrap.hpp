#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <ClapTrap.hpp>
#include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	virtual ~FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap &operator=(FragTrap const &rhs);

	void highFivesGuys(void);
};

#endif // SCAVTRAP_HPP
