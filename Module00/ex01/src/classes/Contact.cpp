#include <Contact.hpp>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName, unsigned int phoneNumber,
                 const std::string& darkestSecret)
				 : firstName(firstName),
				   lastName(lastName),
				   nickName(nickName),
				   darkestSecret(darkestSecret),
				   phoneNumber(phoneNumber),
				   isEmpty(false) {
}
Contact::Contact() {
	this->isEmpty = true;
}

Contact::~Contact() {}
Contact::Contact(const Contact &other) {
	*this = other;
}
Contact &Contact::operator=(const Contact &other) {
	if (this == &other) {
		return *this;
	}
	
	firstName = other.firstName;
	lastName = other.lastName;
	nickName = other.nickName;
	darkestSecret = other.darkestSecret;
	phoneNumber = other.phoneNumber;
	isEmpty = false;
	
	return *this;
}
void Contact::writeOutput(unsigned int idx) {
	std::cout << std::setw(COLUMN_WIDTH) << idx << COLUMN_SEPARATOR;
	std::cout << std::setw(COLUMN_WIDTH) << firstName << COLUMN_SEPARATOR;
	std::cout << std::setw(COLUMN_WIDTH) << lastName << COLUMN_SEPARATOR;
	std::cout << std::setw(COLUMN_WIDTH) << nickName << std::endl;
}
Contact Contact::getContactFromInput()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	unsigned long phoneNumber;  // Note the change to 'unsigned long'
	std::string darkestSecret;
	
	std::cout << "First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nick Name: ";
	std::getline(std::cin, nickName);
	std::cout << "Phone Number: ";
	while (!(std::cin >> phoneNumber)) {
		std::cin.clear(); // Clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
		std::cout << "Invalid input. Please enter a valid phone number: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	
	std::cout << firstName << " " << lastName << " " << nickName << " " << phoneNumber << " " << darkestSecret << std::endl;
	return Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}