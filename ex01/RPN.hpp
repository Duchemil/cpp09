#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <stack>
#include <iostream>
#include <string>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

	void calculate(std::string str);

};

#endif
