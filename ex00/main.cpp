#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error \nArgument count is wrong." << '\n';
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Unable to open " << argv[1] << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    inputExchange(file, exchange);
    return 0;
}
