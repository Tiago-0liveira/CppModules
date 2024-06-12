#include <MateriaSource.hpp>


MateriaSource::~MateriaSource()
{
    for (int i=0; i < MATERIAS_NUM; i++)
        materias[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i=0; i < MATERIAS_NUM; i++)
    {
        if (materias[i] == NULL)
            materias[i] = materia;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i=0; i < MATERIAS_NUM; i++)
    {
        if (materias[i] != NULL && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}