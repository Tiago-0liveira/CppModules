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
		//std::cout << "Record<date=" << r.date << ",value=" << r.value << ">" << std::endl;
		if (!parse_error)
		{
			m_data[r.date] = r.value;
		}
	}
	if (m_data.size() == 0)
	{
		throw std::runtime_error("Data.csv cannot be empty!");
	}
	file.close();
}

BitcoinExchange::Record BitcoinExchange::parseLine(const std::string &raw_line, bool &error, char sep)
{
	error = false;
	std::istringstream ss(raw_line);

	std::string line;

	std::string date;
	float value;

	if (!std::getline(ss, line, sep))
	{
		std::cout << "Error: Invalid csv input." << std::endl;
		error = true;
		return Record("", 0);
	}
	date = trim(line);
	if (!std::getline(ss, line, sep) || !validDate(date))
	{
		std::cout << date << "||Error: Invalid csv format or date." << std::endl;
		error = true;
		return Record("", 0);
	}
	line = trim(line);
	value = std::strtof(trim(line).c_str(), NULL);
	if (errno == ERANGE || (sep == '|' && !validValue(value)) || value < 0)
	{
		std::cout << line << "||Error: Wrong value format." << std::endl;
		error = true;
		return Record("", 0);
	}
	return Record(date, value);
}

BitcoinExchange::Record BitcoinExchange::parseDatabaseLine(const std::string &line, bool &error)
{
	return parseLine(line, error, ',');
}

BitcoinExchange::Record BitcoinExchange::parseInputLine(const std::string &line, bool &error)
{
	return parseLine(line, error, '|');
}

float BitcoinExchange::applyExchangeRate(const std::string &date, float amount) const
{
	std::map<std::string, float>::const_iterator it = m_data.begin();
	std::map<std::string, float>::const_iterator itend = m_data.end();

	float last_v = 0;
	while (it != itend)
	{
		if (date <= it->first)
		{
			if (date == it->first)
				last_v = it->second;
			break;
		}
		last_v = it->second;
		it++;
	}
	return last_v * amount;
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
	std::getline(file, line);
	while (std::getline(file, line))
	{
		Record r = parseInputLine(line, parse_error);
		if (!parse_error)
		{
			float result = applyExchangeRate(r.date, r.value);
			std::cout << r.date << " => " << r.value << " = " << result << std::endl;
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
		if (i == 4 || i == 7)
		{
			if (c != '-')
				return false;
		}
		else if (!std::isdigit(c))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::validValue(float value) const
{
	if (value < 0.0f || value > 1000.0f)
	{
		return false;
	}

	return true;
}

std::string trim(const std::string &str)
{
	std::size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
	{
		return "";
	}

	std::size_t last = str.find_last_not_of(" \t\n\r\f\v");

	return str.substr(first, last - first + 1);
}