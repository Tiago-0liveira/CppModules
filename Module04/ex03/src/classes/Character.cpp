#include <Character.hpp>

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character() {}
Character::Character(const Character &copy)
{
	// TODO:
}

Character &Character::operator=(const Character &rhs)
{
	// TODO:
	return *this;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
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
	if (idx >= 0 && idx < 4)
	{
		inventory[idx] = NULL;
	}
}
void Character::use(int idx, ICharacter &target)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			inventory[i]->use(target);
	}
}