#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> _vector, std::deque<int> _deque)
{
	this->_vector = _vector;
	this->_deque = _deque;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vector = other._vector;
	this->_deque = other._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::add_param(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		std::stringstream ss(arg);
		int num;
		ss >> num;
		this->_deque.push_back(num);
		this->_vector.push_back(num);
	}
}

void PmergeMe::merge_insertion_sort(std::vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_insertion_sort(vec, left, mid);
        merge_insertion_sort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

void PmergeMe::merge_insertion_sort(std::deque<int> &deq, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_insertion_sort(deq, left, mid);
        merge_insertion_sort(deq, mid + 1, right);

        merge(deq, left, mid, right);
    }
}

void PmergeMe::merge(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            ++i;
        }
        else
        {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        vec[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::merge(std::deque<int> &deq, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = deq[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = deq[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            deq[k] = L[i];
            ++i;
        }
        else
        {
            deq[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        deq[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        deq[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::ford_sort()
{
    clock_t start_vector = clock();
    merge_insertion_sort(this->_vector, 0, this->_vector.size() - 1);
    clock_t end_vector = clock();
    double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;

    clock_t start_deque = clock();
    merge_insertion_sort(this->_deque, 0, this->_deque.size() - 1);
    clock_t end_deque = clock();
    double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: "
              << std::fixed << std::setprecision(5) << time_vector * 1e6 << " us" << std::endl;

    std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: "
              << std::fixed << std::setprecision(5) << time_deque * 1e6 << " us" << std::endl;
}
