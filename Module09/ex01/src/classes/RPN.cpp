#include "RPN.hpp"

RPN::RPN(const std::string &expression) {
    parseExpression(expression);
}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}

int RPN::evaluate() {
    if (!validStack()) {
        throw InvalidExpression();
    }

    std::stack<std::string> tempStack = stack;
    std::stack<int> resultStack;

    while (!tempStack.empty()) {
        std::string token = tempStack.top();
        tempStack.pop();

        if (std::isdigit(token[0]) && token.length() == 1) {
            resultStack.push(std::atoi(token.c_str()));
        } else if (validOperator(token[0]) && token.length() == 1) {
            if (resultStack.size() < 2) {
                throw InvalidExpression();
            }
            int operand2 = resultStack.top();
            resultStack.pop();
            int operand1 = resultStack.top();
            resultStack.pop();

            int result;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                if (operand2 == 0) {
                    throw InvalidExpression();
                }
                result = operand1 / operand2;
            } else {
                throw InvalidExpression();
            }

            resultStack.push(result);
        } else {
            throw InvalidExpression();
        }
    }

    if (resultStack.size() != 1) {
        throw InvalidExpression();
    }

    return resultStack.top();
}

const char *RPN::InvalidExpression::what() const throw() {
    return "Invalid RPN expression.";
}

bool RPN::validOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::validStack() const {
    std::stack<std::string> tempStack = stack;
    int count = 0;

    while (!tempStack.empty()) {
        std::string top = tempStack.top();
        tempStack.pop();

		if (std::isdigit(top[0]) && top.length() == 1) {
            count++;
        } else if (validOperator(top[0]) && top.length() == 1) {
            count--;
        }

        if (count < 1) {
            return false;
        }
    }

    return count == 1;
}

void RPN::parseExpression(const std::string &expression) {
    std::istringstream stream(expression);
    std::string token;
	std::stack<std::string> tempStack;

    while (stream >> token) {
		if (token.length() == 1 && (std::isdigit(token[0]) || validOperator(token[0]))) {
            stack.push(token);
        } else {
            throw InvalidExpression();
        }
    }
	
	// Reverse the stack
	while (!stack.empty()) {
        tempStack.push(stack.top());
        stack.pop();
    }
	stack = tempStack;
}