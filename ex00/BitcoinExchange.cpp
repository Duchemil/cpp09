#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;

    if (!file || !file.is_open())
    {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return;
    }

    std::getline(file, line); // skip header
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string priceStr;
        double price;

        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
        {
            std::stringstream priceStream(priceStr);
            priceStream >> price;
            if (!priceStream.fail())
            {
                bitcoinPrices[date] = price;
            }
        }
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	bitcoinPrices = other.bitcoinPrices;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		bitcoinPrices = other.bitcoinPrices;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::addBitcoinPrice(std::string date, double price)
{
	bitcoinPrices[date] = price;
}

double BitcoinExchange::getBitcoinPrice(std::string date) const
{
	std::map<std::string, double>::const_iterator it = bitcoinPrices.lower_bound(date);
    if (it == bitcoinPrices.end() || it->first != date)
    {
        if (it != bitcoinPrices.begin())
            --it;
        else
        {
            std::cerr << "No valid date found for entry: " << date << std::endl;
            return -1; // Indicate an error
        }
    }
    return it->second;
}

void BitcoinExchange::printBitcoinPrices()
{
    for (std::map<std::string, double>::iterator it = bitcoinPrices.begin(); it != bitcoinPrices.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

bool isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 != 0)
        return false;
    return true;
}

bool isValidDate(const std::string &date)
{
    if (date.length() != 10)
    {
        std::cerr << "Error: Date format is incorrect, expected YYYY-MM-DD" << std::endl;
        return false;
    }

    if (date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: Date format is incorrect, expected YYYY-MM-DD" << std::endl;
        return false;
    }

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
        {
            std::cerr << "Error: Date contains non-digit characters" << std::endl;
            return false;
        }
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009)
    {
        std::cerr << "Error: Year out of range (<2009)" << std::endl;
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: Month out of range (1-12)" << std::endl;
        return false;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
    {
        std::cerr << "Error: Day out of range for the given month" << std::endl;
        return false;
    }

    return true;
}

bool isValidValue(const std::string &valueStr, double &value)
{
    std::istringstream iss(valueStr);
    iss >> value;
    if (iss.fail() || !iss.eof())
    {
        std::cerr << "Error: Value is not a valid number" << std::endl;
        return false;
    }
    if (value < 0 || value > 1000)
    {
        std::cerr << "Error: Value out of range (0-1000)" << std::endl;
        return false;
    }
    return true;
}

void inputExchange(std::ifstream &file, const BitcoinExchange &exchange)
{
    std::string line;

	// Skip header
	if (!std::getline(file, line))
        return;

    std::cout << "Input date | Nb of btc | Total value " << std::endl;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;
        double value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date.erase(date.find_last_not_of(" \n\r\t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

            if (isValidDate(date) && isValidValue(valueStr, value))
            {
                double price = exchange.getBitcoinPrice(date);
                if (price != -1)
                    std::cout << date << " => " << value << " = " << (price * value) << std::endl;
            }
            else
                ;
        }
        else
            ;
    }
}
