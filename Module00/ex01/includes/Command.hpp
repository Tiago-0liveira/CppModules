#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

enum CommandType {
	ADD,
	SEARCH,
	EXIT,
	INVALID
};

CommandType inputMatch(const std::string& command);

#endif //COMMAND_HPP
