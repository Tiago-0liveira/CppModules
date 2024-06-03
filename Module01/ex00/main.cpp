#include <Zombie.hpp>

/* Allocate new zombie */
Zombie *newZombie(std::string name);
/* Announce a zombie with <name> */
void	randomChump(std::string name);

int main(void)
{
	Zombie test ("Ze");
	Zombie *test1 = newZombie("Rui");
	test.announce();
	test1->announce();
	randomChump("Antonio");
	delete test1;
}