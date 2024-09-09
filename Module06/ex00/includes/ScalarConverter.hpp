#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>

class ScalarConverter
{
private:
	ScalarConverter();

	static char string_to_char(const std::string &param);
	static int string_to_int(const std::string &param);
	static float string_to_float(const std::string &param);
	static double string_to_double(const std::string &param);

	enum Type {
		Char, Int, Float, Double, PseudoLiteral, Undefined
	};
	
	static Type getType(const std::string &param);
	static bool isPseudoLiteral(const std::string &param);
public:	
	~ScalarConverter();
	ScalarConverter(const ScalarConverter & copy);
	ScalarConverter &operator=(ScalarConverter const & rhs);
	
	static void convert(const std::string &param);

	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif // SCALARCONVERTER_HPP		