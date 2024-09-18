#include <BitcoinExchange.hpp>
#include <sstream>

const std::string &BitcoinExchange::databasePath = "data.csv";

BitcoinExchange::Record::Record(const std::string &d, float v) : date(d), value(v) {}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file(databasePath.c_str());
	
	if (!file.good())
	{
		std::cerr << "Error: Database file does not exist." << std::endl;
		throw std::runtime_error("Database file does not exist.");
	}
	loadDatabase(BitcoinExchange::databasePath);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	m_data = other.m_data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		m_data = other.m_data;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string &database)
{
	std::ifstream file(database.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << database << std::endl;
		return;
	}

	std::string line;
	bool parse_error = false;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		Record r = parseDatabaseLine(line, parse_error);
		if (!parse_error)
		{
			m_data[r.date] = r.value;
		}
	}
	file.close();
}

BitcoinExchange::Record BitcoinExchange::parseLine(const std::string &raw_line, bool &error, char sep)
{
	std::istringstream ss(raw_line);
	
	std::string line;
	
	std::string date;
	float value;
	
	std::cout << "parseLine::raw_line:" << raw_line << "||";
	if (!std::getline(ss, line, sep))
	{
		std::cout << "Error: could not parse line." << std::endl;
		error = true;
		return Record("", 0);
	}
	std::cout << "date::" << line << "||";
	date = trim(line);
	if (!std::getline(ss, line, sep) || !validDate(date))
	{
		std::cout << "Error: could not parse line." << std::endl;
		error = true;
		return Record("", 0);
	}
	std::cout << "value::" << line << "||";
	line = trim(line);
	value = std::strtof(trim(line).c_str(), NULL);
	if (errno == ERANGE || !validValue(value))
	{
		std::cout << "Error: could not parse value." << std::endl;
		error = true;
		return Record("", 0);
	}
	std::cout << std::endl;
	
	return Record(date, value);
}

BitcoinExchange::Record BitcoinExchange::parseDatabaseLine(const std::string &line, bool &error)
{
	return parseLine(line, error, ',');
}

BitcoinExchange::Record BitcoinExchange::parseInputLine(const std::string &line, bool &error)
{
	return parseLine(line, error, ' ');
}

float BitcoinExchange::applyExchangeRate(const std::string &date, float amount) const
{
	std::map<std::string, float>::const_iterator it = m_data.find(date);
	if (it == m_data.end())
	{
		std::cerr << "Error: could not find exchange rate for date " << date << std::endl;
		throw std::runtime_error("Could not find exchange rate for date.");
	}
	return it->second * amount;
}

void BitcoinExchange::applyRatesToFile(const std::string &inputFile)
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << inputFile << std::endl;
		throw std::runtime_error("Could not open file.");
	}
	
	std::string line;
	bool parse_error = false;
	while (std::getline(file, line))
	{
		Record r = parseInputLine(line, parse_error);
		if (!parse_error)
		{
			float result = applyExchangeRate(r.date, r.value);
			std::cout << r.date << " " << result << std::endl;
		}
	}
	file.close();
}

bool BitcoinExchange::validDate(const std::string &date) const
{
	if (date.length() != 10)
		return false;
	for (int i = 0; i < 10; i++)
	{
		char c = date.at(i);
		if (i == 4 && i == 7)
		{
			
		} else if 
	}


	return true;
}


bool BitcoinExchange::validValue(float value) const
{
	if (value < 0.0f || value > 1000.0f)
	{
		std::cout << "Invalid date!" << std::endl;
		return false;
	}

	return true;
}

std::string trim(const std::string& str)
{
    std::size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        return "";
    }
    
    std::size_t last = str.find_last_not_of(" \t\n\r\f\v");
    
    return str.substr(first, last - first + 1);
}