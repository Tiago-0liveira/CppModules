#include <PhoneBook.hpp>
#include <Command.hpp>
#include <Contact.hpp>
#include <iostream>

int main()
{
	PhoneBook   phoneBook;
	std::string input;
	CommandType commandType;
	
	do
	{
		std::cout << " > ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		commandType = inputMatch(input);
		switch (commandType)
		{
			case ADD:
				phoneBook.addContact(Contact::getContactFromInput());
				break;
			case SEARCH:
				phoneBook.searchContact();
				break;
			case EXIT:
				break;
			case INVALID:
				std::cout << "Invalid command" << std::endl;
				break;
		}
	} while (input != "EXIT");
	
	return 0;
}
