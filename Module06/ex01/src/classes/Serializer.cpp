#include <Serializer.hpp>

Serializer::Serializer() {}
Serializer::~Serializer() {}

Serializer::Serializer(const Serializer & copy) {}

Serializer &Serializer::operator=(Serializer const & rhs) {}


uintptr_t Serializer::serialize(Data* ptr) 
{
    return 0;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return new Data(0,0);
}
