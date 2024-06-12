#include <Character.hpp>

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = NULL;
}

Character::~Character() {}
Character::Character(const Character &copy)
{
	(void)copy;
	// TODO:
}

Character &Character::operator=(const Character &rhs)
{
	(void)rhs;
	// TODO:
	return *this;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (inventory[i] != NULL)
		{
			inventory[i] = m;
			return;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < INV_SIZE)
	{
		inventory[idx] = NULL;
	}
}
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < INV_SIZE && inventory[idx] != NULL)
		inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return name;
}