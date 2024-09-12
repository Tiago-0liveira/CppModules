#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::ErrorException::what() const throw()
{
    return "Conversion Error";
}

bool ScalarConverter::isPseudoLiteral(const std::string &param)
{
    static std::string pseudoLiterals[6] = {
        "-inff", "+inff", "nanf", "-inf", "+inf", "nan"
    }; 
    int i = 0;
    for (; i < 6; i++) {
        if (param.compare(pseudoLiterals[i]) == 0)
            return true;
    }
    return false;
}

ScalarConverter::Type ScalarConverter::getType(const std::string &param)
{
    if (param.empty()) return Undefined;
    else if (isPseudoLiteral(param)) return PseudoLiteral;
	
	if (param.length() == 1 && !isdigit(param[0])) return Char; // Single non-digit character
	if (param.find_first_not_of("0123456789-") == std::string::npos) return Int; // All digits (and possibly a leading '-')
	
	size_t dot_idx = param.find('.');
	if (dot_idx != std::string::npos) {
		bool found_f = false;
		for (size_t i = 0; i < param.length(); i++) {
			if (param.at(i) == 'f') {
				if (found_f) return Undefined;
				found_f = true;
			} else if (!isdigit(param[i]) && param[i] != '.') {
				return Undefined;
			}
		}
		if (found_f) return Float;
		return Double;
	}
	
	return Undefined;
}

void ScalarConverter::convert(const std::string &param)
{
	ScalarConverter::Type type = getType(param);
	char res_char;
	int res_int;
	float res_float;
	double res_double;
	
	try {
		switch (type) {
			case Char:
				res_char = string_to_char(param);
				res_int = static_cast<int>(res_char);
				res_float = static_cast<float>(res_char);
				res_double = static_cast<double>(res_char);
				break;
			
			case Int:
				res_int = string_to_int(param);
				res_char = (res_int >= 0 && res_int <= 127 && isprint(res_int)) ? static_cast<char>(res_int) : '\0';
				res_float = static_cast<float>(res_int);
				res_double = static_cast<double>(res_int);
				break;
			
			case Float:
				res_float = string_to_float(param);
				res_int = static_cast<int>(res_float);
				res_double = static_cast<double>(res_float);
				res_char = (res_int >= 0 && res_int <= 127 && isprint(res_int)) ? static_cast<char>(res_int) : '\0';
				break;
			
			case Double:
				res_double = string_to_double(param);
				res_float = static_cast<float>(res_double);
				res_int = static_cast<int>(res_double);
				res_char = (res_int >= 0 && res_int <= 127 && isprint(res_int)) ? static_cast<char>(res_int) : '\0';
				break;
			
			case PseudoLiteral:
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				if (param.compare("-inf") == 0 || param.compare("+inf") == 0 || param.compare("nan") == 0)
					std::cout << "float: " << param << "f" << std::endl;
				else
					std::cout << "float: " << param << std::endl;
				if (param.compare("-inf") == 0 || param.compare("+inf") == 0 || param.compare("nan") == 0)
					std::cout << "double: " << param << std::endl;
				else {
					std::string copy = param;
					copy.erase(copy.length() - 1);
					std::cout << "double: " << copy << std::endl;
				}
				return;
			
			case Undefined:
				throw ErrorException();
		}
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		
		return;
	}
	
	// Print char
	if (type != PseudoLiteral && type != Undefined) {
		if (res_int < std::numeric_limits<char>::min() || res_int > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else if (res_char == '\0' || !isprint(res_char))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << res_char << "'" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	
	// Print int
	if (type == Char || type == Int || type == Float || type == Double) {
		if ((type == Float || type == Double) &&
				(res_float < std::numeric_limits<int>::min() ||
				res_float > std::numeric_limits<int>::max() ||
			    res_double < std::numeric_limits<int>::min() ||
				res_double > std::numeric_limits<int>::max())) {
			std::cout << "int: impossible" << std::endl;
		} else
			std::cout << "int: " << res_int << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
	
	// Print float with proper formatting
	if (type == Char || type == Int || type == Float || type == Double) {
		std::cout << std::fixed << "float: " << res_float << "f" << std::endl;
	} else {
		std::cout << "float: impossible" << std::endl;
	}
	
	// Print double with proper formatting
	if (type == Char || type == Int || type == Float || type == Double) {
		std::cout << std::fixed << "double: " << res_double << std::endl;
	} else {
		std::cout << "double: impossible" << std::endl;
	}
}

char ScalarConverter::string_to_char(const std::string &param)
{
	if (param.length() == 1 && isprint(param[0])) return param[0];
	throw ErrorException();
}

int ScalarConverter::string_to_int(const std::string &param)
{
	long int value = std::strtol(param.c_str(), NULL, 10);
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || errno == ERANGE)
		throw ErrorException();
	return static_cast<int>(value);
}

float ScalarConverter::string_to_float(const std::string &param)
{
	float value = std::strtof(param.c_str(), NULL);
	if (value == HUGE_VALF || value == -HUGE_VALF || errno == ERANGE)
		throw ErrorException();
	return value;
}

double ScalarConverter::string_to_double(const std::string &param)
{
	double value = std::strtod(param.c_str(), NULL);
	if (value == HUGE_VAL || value == -HUGE_VAL || errno == ERANGE)
		throw ErrorException();
	return value;
}
