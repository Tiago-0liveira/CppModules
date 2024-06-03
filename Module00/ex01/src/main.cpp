#include <PhoneBook.hpp>
#include <Command.hpp>
#include <Contact.hpp>
#include <iostream>
#include <utils.hpp>

int main()
{
	PhoneBook   phoneBook;
	std::string input;
	CommandType commandType;
	
	do
	{
		input = getValidStringInput(" > ", "Invalid command");
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
				return 0;
			case INVALID:
				std::cout << "Invalid command" << std::endl;
				break;
		}
	} while (true);
	
	return 0;
}
