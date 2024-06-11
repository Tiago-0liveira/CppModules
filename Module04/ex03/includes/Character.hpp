#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>
#include <AMateria.hpp>

class Character : public ICharacter
{
public:
	Character(std::string const &name);
	~Character();
	Character(const Character &copy);
	Character &operator=(const Character &rhs);

	std::string const &getName() const override;
	void equip(AMateria *m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter &target) override;

private:
	std::string name;
	AMateria *inventory[4];
}

#endif // CHARACTER_HPP