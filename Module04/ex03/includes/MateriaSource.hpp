#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>
#include <AMateria.hpp>

#define MATERIAS_NUM 4

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const & other);
	MateriaSource& operator=(MateriaSource const & other);

	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);

private:
	AMateria *materias[MATERIAS_NUM];
};


#endif // MATERIASROUCE_HPP