#include "RPN.hpp"

bool is_valid(const std::string &input)
{
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            continue;
        }
        else if (input[i] == ' ')
        {
            if (i == 0 || i == input.length() - 1 || input[i - 1] == ' ' || input[i + 1] == ' ')
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error \nArgument count is wrong." << '\n';
        return 1;
    }

    RPN rpn;
    rpn.calculate(argv[1]);
    return 0;
}
