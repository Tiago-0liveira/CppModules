#include <MateriaSource.hpp>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < MATERIAS_NUM; ++i)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < MATERIAS_NUM; ++i)
        materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other)
{
    if (this != &other) {
        for (int i = 0; i < MATERIAS_NUM; ++i) {
            if (materias[i])
                delete materias[i];
            materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MATERIAS_NUM; ++i)
        if (materias[i])
            delete materias[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i=0; i < MATERIAS_NUM; i++)
    {
        if (materias[i] == NULL)
        {
			materias[i] = materia;
			return ;
		}
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