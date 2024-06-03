#include <Zombie.hpp>

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zombiesPtr = zombieHorde(5, "Rui");

	if (!zombiesPtr)
		return 1;
	for(int k = 0; k < 5; k++)
		zombiesPtr[k].announce();

	delete[] zombiesPtr;
	return 0;
}