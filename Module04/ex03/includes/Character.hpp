#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>
#include <AMateria.hpp>

#define INV_SIZE 4

class Character : public ICharacter
{
public:
	Character(std::string const &name);
	virtual ~Character();
	Character(const Character &copy);
	Character &operator=(const Character &rhs);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

private:
	std::string name;
	AMateria *inventory[INV_SIZE];
};

#endif // CHARACTER_HPP