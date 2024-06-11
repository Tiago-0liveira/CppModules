#include <AAnimal.hpp>

const std::string &AAnimal::getType(void) const
{
	return type;
}

AAnimal::AAnimal(std::string const &type): type(type) {}

AAnimal::~AAnimal() {}