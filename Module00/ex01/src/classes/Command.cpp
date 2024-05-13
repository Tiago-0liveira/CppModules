#include <Command.hpp>

CommandType inputMatch(const std::string& command) {
	if (command == "ADD")
		return ADD;
	else if (command == "SEARCH")
		return SEARCH;
	else if (command == "EXIT")
		return EXIT;
	else
		return INVALID;
}
