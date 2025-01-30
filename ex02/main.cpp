#include "PmergeMe.hpp"

bool is_valid(int argc, char **argv)
{
    std::set<int> numbers;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        for (std::string::size_type j = 0; j < arg.size(); ++j)
        {
            if (!isdigit(arg[j]))
                return false;
        }
        std::stringstream ss(arg);
        int num;
        ss >> num;
        if (num < 0 || !numbers.insert(num).second)
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    try
    {
        if (argc <= 2) {
            throw std::invalid_argument("Error: Argument count is wrong.");
        }

        if (!is_valid(argc, argv)) {
            throw std::invalid_argument("Error: Invalid input. Ensure all numbers are positive and not duplicated.");
        }

        PmergeMe pmerge;
        pmerge.add_param(argc, argv);
        pmerge.ford_sort();

        std::vector<int> sorted_vector = pmerge.get_vector();
        std::deque<int> sorted_deque = pmerge.get_deque();

        std::cout << "Sorted vector: ";
        for (size_t i = 0; i < sorted_vector.size(); ++i)
            std::cout << sorted_vector[i] << " ";
        std::cout << std::endl;

        std::cout << "Sorted deque: ";
        for (size_t i = 0; i < sorted_deque.size(); ++i)
            std::cout << sorted_deque[i] << " ";
        std::cout << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
