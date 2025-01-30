#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <set>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

	public:
		PmergeMe();
		PmergeMe(std::vector<int> _vector, std::deque<int> _deque);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void add_param(int argc, char **argv);
		void ford_sort();

		std::vector<int> get_vector() const { return this->_vector; }
		std::deque<int> get_deque() const { return this->_deque; }
		void merge_insertion_sort(std::vector<int> &vec, int left, int right);
        void merge_insertion_sort(std::deque<int> &deq, int left, int right);
        void merge(std::vector<int> &vec, int left, int mid, int right);
        void merge(std::deque<int> &deq, int left, int mid, int right);

};

#endif
