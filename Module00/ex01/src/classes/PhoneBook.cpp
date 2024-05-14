#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
	contactIdx = 0;
}
PhoneBook::PhoneBook(const PhoneBook& other) {
	contactIdx = other.contactIdx;
	for (unsigned int i = 0; i < MAX_CONTACTS; i++) {
		contacts[i] = other.contacts[i];
	}
}
PhoneBook::~PhoneBook() {}
PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this == &other) {
		return *this;
	}
	contactIdx = other.contactIdx;
	for (unsigned int i = 0; i < MAX_CONTACTS; i++) {
		contacts[i] = other.contacts[i];
	}
	return *this;
}

void PhoneBook::addContact(const Contact& contact) {
	if (contactIdx == MAX_CONTACTS)
		contactIdx = 0;
	
	contacts[contactIdx++] = contact;
}
void PhoneBook::searchContact() {
	std::cout << std::setw(COLUMN_WIDTH) << "Index" << COLUMN_SEPARATOR;
	std::cout << std::setw(COLUMN_WIDTH) << "First Name" << COLUMN_SEPARATOR;
	std::cout << std::setw(COLUMN_WIDTH) << "Last Name" << COLUMN_SEPARATOR;
	std::cout << std::setw(COLUMN_WIDTH) << "Nickname" << std::endl;
	for (unsigned int i = 0; i < MAX_CONTACTS; i++) {
		if (contacts[i].isEmpty)
			continue;
		contacts[i].writeOutput(uIntToString(i));
	}
}