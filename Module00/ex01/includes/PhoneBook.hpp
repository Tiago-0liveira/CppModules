#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <Contact.hpp>
#include <iostream>

#define MAX_CONTACTS 8
#ifndef COLUMN_WIDTH
	#define COLUMN_WIDTH 10
#endif
#ifndef COLUMN_SEPARATOR
	#define COLUMN_SEPARATOR "|"
#endif

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook& other);
	PhoneBook& operator=(const PhoneBook& other);
	
	void addContact(const Contact& contact);
	void searchContact();
private:
	Contact         contacts[MAX_CONTACTS];
	unsigned int    contactIdx;
};

#endif // PHONEBOOK_HPP
