#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	_stack = other._stack;
	return *this;
}

void RPN::calculate(std::string str)
{
	for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (isdigit(str[i]))
            _stack.push(str[i] - '0');
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            calculator(str[i]);
    }
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid input.");
	std::cout << _stack.top() << std::endl;
}

void RPN::calculator(char op)
{
	int a;
	int b;
	int result;

	if (_stack.size() < 2)
        throw std::runtime_error("Error: Not enough operands.");

	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();

	switch (op)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
            {
                throw std::runtime_error("Error: Division by zero.");
            }
            result = a / b;
            break;
        default:
            throw std::runtime_error("Error: Invalid operator.");
    }
	_stack.push(result);
}
