#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <exception>

class RPN
{
public:
	RPN(const std::string &expression);
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	void parseExpression(const std::string &expression);
	int evaluate();

	class InvalidExpression : public std::exception
	{
	public:
		const char *what() const throw();
	};
private:
	bool validOperator(char c) const;
	bool validStack() const;

	std::stack<std::string> stack;
};

#endif //RPN_HPP
