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
Contact::Contact(const Contact &other)
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
	//std::cout << std::setw(COLUMN_WIDTH) << idx << COLUMN_SEPARATOR;
	//std::cout << std::setw(COLUMN_WIDTH) << firstName << COLUMN_SEPARATOR;
	//std::cout << std::setw(COLUMN_WIDTH) << lastName << COLUMN_SEPARATOR;
	//std::cout << std::setw(COLUMN_WIDTH) << nickName << std::endl;
	std::cout << stringSetSize(idx, COLUMN_WIDTH) << COLUMN_SEPARATOR;
	std::cout << stringSetSize(firstName, COLUMN_WIDTH) << COLUMN_SEPARATOR;
	std::cout << stringSetSize(lastName, COLUMN_WIDTH) << COLUMN_SEPARATOR;
	std::cout << stringSetSize(nickName, COLUMN_WIDTH) << std::endl;
}
Contact Contact::getContactFromInput()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	firstName = getValidStringInput("First Name: ");
	lastName = getValidStringInput("Last Name: ");
	nickName = getValidStringInput("Nick Name: ");
	phoneNumber = getValidStringInput("Phone Number: ");
	darkestSecret = getValidStringInput("Darkest Secret: ");
	
	return Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}