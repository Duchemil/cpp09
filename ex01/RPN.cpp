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
	(void)str;
		return;
}
