#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <utils.hpp>
#ifndef COLUMN_WIDTH
	#define COLUMN_WIDTH 10
#endif
#ifndef COLUMN_SEPARATOR
	#define COLUMN_SEPARATOR "|"
#endif

class Contact {
public:
	Contact();
	Contact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret);
	~Contact();
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);
	void writeOutput(const std::string& idx);
	void writeDetailedOutput();
	static Contact getContactFromInput();
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	std::string	phoneNumber;
public:
	bool    	    isEmpty;
};

#endif //CONTACT_HPP
