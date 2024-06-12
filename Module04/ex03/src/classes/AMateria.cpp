#include <AMateria.hpp>

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(const AMateria &copy): type(copy.type) {}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		// We do not want to copy anything for now
		(void)rhs;
	}
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const 
{
	return type;
}

void AMateria::use(ICharacter &target) { (void)target; }