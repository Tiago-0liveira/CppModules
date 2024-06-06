#include <Contact.hpp>

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber,
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
Contact::Contact(const Contact &other) : isEmpty(false)
{
	*this = other;
}
Contact &Contact::operator=(const Contact &other)
{
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
void Contact::writeOutput(const std::string& idx)
{
	std::cout << stringSetSize(idx, COLUMN_WIDTH) << COLUMN_SEPARATOR;
	std::cout << stringSetSize(firstName, COLUMN_WIDTH) << COLUMN_SEPARATOR;
	std::cout << stringSetSize(lastName, COLUMN_WIDTH) << COLUMN_SEPARATOR;
	std::cout << stringSetSize(nickName, COLUMN_WIDTH) << std::endl;
}

void Contact::writeDetailedOutput()
{
	std::cout << "First Name:     " << firstName << std::endl;
	std::cout << "Last Name:      " << lastName << std::endl;
	std::cout << "Nick Name:      " << nickName << std::endl;
	std::cout << "Phone Number:   " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

Contact Contact::getContactFromInput()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	firstName = getValidStringInput("First Name: ");
	replaceTabs(firstName);
	lastName = getValidStringInput("Last Name: ");
	replaceTabs(lastName);
	nickName = getValidStringInput("Nick Name: ");
	replaceTabs(nickName);
	phoneNumber = getValidStringInput("Phone Number: ");
	replaceTabs(phoneNumber);
	darkestSecret = getValidStringInput("Darkest Secret: ");
	replaceTabs(darkestSecret);
	
	return Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}