#include "RPN.hpp"

bool is_valid(const std::string &input)
{
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            continue;
        else if (input[i] == ' ')
        {
            if (i == 0 || i == input.length() - 1 || input[i - 1] == ' ' || input[i + 1] == ' ')
                return false;
        }
        else
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2) {
            throw std::invalid_argument("Error: Argument count is wrong.");
        }

        if (!is_valid(argv[1])) {
            throw std::invalid_argument("Error: Invalid input.");
        }

        RPN rpn;
        rpn.calculate(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
