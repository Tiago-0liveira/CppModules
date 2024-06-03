#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

enum e_harl_level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	static e_harl_level _getLevel(const std::string &level);

	public:
		void complain(const std::string& level);
};

#endif //HARL_HPP