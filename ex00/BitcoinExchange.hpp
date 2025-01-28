#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double> bitcoinPrices;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void addBitcoinPrice(std::string date, double price);
		double getBitcoinPrice(std::string date) const;
		void printBitcoinPrices();
};

void inputExchange(std::ifstream &file, const BitcoinExchange &exchange);

#endif
