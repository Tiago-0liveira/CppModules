#include <utils.hpp>

std::string getValidStringInput(const std::string &prompt)
{
	return getValidStringInput(prompt, "");
}

std::string getValidStringInput(const std::string &prompt, const std::string &error_msg)
{
	std::string input;
	std::string tmp;

	if (std::cin.eof())
	{
		std::cout << std::endl;
		exit(EXIT_FAILURE);
	}
	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		tmp = trim(input);
		if (!error_msg.empty() && !std::cin.eof() && tmp.empty())
			std::cout << error_msg << std::endl;
	} while (!std::cin.eof() && tmp.empty());
	return tmp;
}

std::string trim(const std::string &str)
{
	size_t first = 0;
	size_t last = str.size() - 1;

	while (first <= last && std::isspace(static_cast<unsigned char>(str[first])))
	{
		++first;
	}
	while (last >= first && std::isspace(static_cast<unsigned char>(str[last])))
	{
		--last;
	}
	return str.substr(first, last - first + 1);
}

/* Will check if str is size size, if not, fill with spaces until size, else remove everything after size and put a dot */
std::string stringSetSize(const std::string &str, size_t size)
{
	if (str.length() > size)
	{
		return str.substr(0, size - 1) + ".";
	}
	std::string res;
	while (res.length() + str.length() < size)
		res += " ";
	return res + str;
}

std::string uIntToString(unsigned int idx)
{
	if (idx > 8)
	{
		throw std::out_of_range("Index out of range. It must be between 0 and 8.");
	}

	char buffer[2];
	buffer[0] = idx + '0';
	buffer[1] = '\0';

	return std::string(buffer);
}

void replaceTabs(std::string& str)
{
    for (std::size_t i = 0; i < str.size(); ++i)
	{
        if (str[i] == '\t')
            str[i] = ' ';
    }
}