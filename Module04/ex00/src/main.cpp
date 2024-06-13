#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << "---------------------" << std::endl;

	const WrongAnimal *wrongAnimalWrongCat = new WrongCat();

	std::cout << wrongAnimalWrongCat->getType() << " " << std::endl;

	wrongAnimalWrongCat->makeSound();

	const WrongCat *wrongCat = new WrongCat();

	wrongCat->makeSound();
	
	delete wrongAnimalWrongCat;
	delete wrongCat;

	return 0;
}