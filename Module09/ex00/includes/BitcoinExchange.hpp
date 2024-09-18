#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <ctime>
#include <fstream>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	float applyExchangeRate(const std::string &date, float amount) const;
	
	void applyRatesToFile(const std::string &inputFile);
	bool validDate(const std::string &date) const;
	bool validValue(float value) const;
	
	struct Record
	{
		Record(const std::string &d, float v);
		const std::string &date;
		float value;
	};
private:
	void loadDatabase(const std::string &database);
	
	Record parseLine(const std::string &line, bool &error, char sep);
	Record parseDatabaseLine(const std::string &line, bool &error);
	Record parseInputLine(const std::string &line, bool &error);
	
	std::map<std::string, float> m_data;
	static const std::string &databasePath;
};

std::string trim(const std::string& str);

#endif //BITCOINEXCHANGE_HPP
