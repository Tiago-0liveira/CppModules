#include <iostream>
#include <Serializer.hpp>


int main()
{
	Data d(42, 42);
	
	uintptr_t serialized = Serializer::serialize(&d);
	
	std::cout << serialized << std::endl;
	
	Data *deserialized = Serializer::deserialize(serialized);
	
	std::cout << deserialized->x << " " << deserialized->y << std::endl;

	deserialized->x = 24;
	deserialized->y = 24;

	std::cout << deserialized->x << " " << deserialized->y << std::endl;
	
	return 0;
}
