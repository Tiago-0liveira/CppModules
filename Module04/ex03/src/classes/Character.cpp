#include <Character.hpp>

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < INV_SIZE; ++i)
        if (inventory[i] != NULL)
            delete inventory[i];
}
Character::Character(const Character &copy)
{
	name = copy.name;
	for (int i = 0; i < INV_SIZE; ++i)
	{
        inventory[i] = copy.inventory[i] ? copy.inventory[i]->clone() : NULL;
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
        name = rhs.name;
        for (int i = 0; i < INV_SIZE; ++i)
		{
            if (inventory[i])
                delete inventory[i];
            inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (!inventory[i])
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
	{
		inventory[idx]->use(target);
	}
}

std::string const & Character::getName() const
{
	return name;
}