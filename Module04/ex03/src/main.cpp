#include <iostream>
#include <MateriaSource.hpp>
#include <Character.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

int main()
{	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character me ("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("cure");
	me.equip(tmp);
	
	Character bob("bob");
	bob.equip(src->createMateria("ice"));

	bob = me;
	bob.use(1, bob);
	
	me.use(0, bob);
	me.use(1, bob);

	
	delete src;

	return 0;
}
