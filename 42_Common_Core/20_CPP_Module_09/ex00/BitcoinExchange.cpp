/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:40:32 by aternero          #+#    #+#             */
/*   Updated: 2026/05/12 17:15:31 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


// --- FUNCIONES UTILITARIAS ---
std::string trim(const std::string &str) {
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

int ft_atoi(const std::string &str) {
	int index = 0, nbr = 0, sign = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+') {
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (isdigit(str[index])) {
		nbr = (nbr * 10) + (str[index] - 48);
		index++;
	}
	return (nbr * sign);
}

float toFloat(const std::string &str) {
	char *end = NULL;
	errno = 0;
	float parsed = std::strtof(str.c_str(), &end);
	if (*end == '\0' && errno != ERANGE)
		return (parsed);
	throw BitcoinExchange::InvalidInput();
}

int charCounter(const std::string &str, char c) {
	int counter = 0;
	for (size_t index = 0; index < str.length(); index++) {
		if (str[index] == c)
			counter++;
	}
	return (counter);
}

/*	ORTHODOX CANONICAL FORM	*/

BitcoinExchange::BitcoinExchange()	{
	throw BitcoinExchange::ReadingInput();
}

BitcoinExchange::BitcoinExchange(const std::string &inputFile) : _inputFile(inputFile), _csvData("data.csv")	{
	_dbMap = loadDB();
	_inputMap = loadInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _inputMap(other._inputMap), _dbMap(other._dbMap), _inputFile(other._inputFile), _csvData(other._csvData)	{ }

BitcoinExchange::~BitcoinExchange()	{ }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)	{
	if (this != &other)	{
		_inputMap = other._inputMap;
		_dbMap = other._dbMap;
		_inputFile = other._inputFile;
		_csvData = other._csvData;
	}
	return (*this);
}

/*	IMPLEMENTATION	*/

void	parseBitcoinExistence(int day, int month, int year)	{
	if (year < 2009)	{
		std::cout << "About the date " << day << "/" << month << "/" << year << ": " << std::endl;
		throw BitcoinExchange::BitcoinExistence();
	}
	if (year == 2009 && month == 1 && day < 2)	{
		std::cout << "About the date " << day << "/" << month << "/" << year << ": " << std::endl;
		throw BitcoinExchange::BitcoinExistence();
	}
	std::time_t now = std::time(0);
	std::tm* 	date = std::localtime(&now);
	if (year > date->tm_year + 1900 || (year == date->tm_year + 1900 && month > date->tm_mon + 1) || (year == date->tm_year + 1900 && month == date->tm_mon + 1 && day > date->tm_mday))
		throw BitcoinExchange::BitcoinExistence();
}

void	parseDay(int day, int month, int year)	{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)	{
		if (day <= 0 || day > 31)
			throw BitcoinExchange::InvalidDay();
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)	{
		if (day <= 0 || day > 30)
			throw BitcoinExchange::InvalidDay();
	}
	else if (month == 2)	{
			if ((year % 4 == 0 && year % 100) || (year % 400 == 0)){
				if (day <= 0 || day > 29)
					throw BitcoinExchange::InvalidDay();
			}
			else
				if (day <= 0 || day > 28)
					throw BitcoinExchange::InvalidDay();
	}
	else
		throw BitcoinExchange::InvalidMonth();
}

std::string	BitcoinExchange::parseDate(const std::string &line)	{

	int	index = 0;
	int	end = line.length() - 1;

	if (line.length() < 10)
	    throw BitcoinExchange::InvalidDate();
	while (isspace(line[index]) == true)
		index++;
	if (charCounter(line, '-') != 2 || (charCounter(line, '-') == 2 && (line[4] != '-' || line[7] != '-')))
		throw BitcoinExchange::InvalidDate();
	while (index < (int)line.length())	{
		if (!isdigit(line[index]) && line[index] != '-')
			throw BitcoinExchange::InvalidDate();
		index++;
	}
	int year = ft_atoi(line.substr(0, 4));
	int month = ft_atoi(line.substr(5, 2));
	int day = ft_atoi(line.substr(8, 2));
	parseDay(day, month, year);
	parseBitcoinExistence(day, month, year);
	index = 0;
	while (isspace(line[index]) == true)
		index++;
	while (isspace(line[end]) == true)
		end--;
	return (line.substr(index, end - index + 1));
}

std::map<std::string, float> BitcoinExchange::loadDB() {
	std::map<std::string, float> dbMap;
	std::ifstream fileContent(_csvData.c_str());
	std::string line;
	size_t position = 0;

	if (!fileContent.is_open()) {
		std::cerr << "Error:\n\tCould not open file: " << _csvData << std::endl;
		return std::map<std::string, float>();
	}
	while (std::getline(fileContent, line)) {
		if (line.find('\r') != std::string::npos)
			line.erase(line.find('\r'));
		line = trim(line);
		if (line.empty())
			continue;
		if ((position == 0 && line.find("date,exchange_rate") == std::string::npos) || line.length() < 10) {
			throw BitcoinExchange::ReadingCSV();
			return std::map<std::string, float>();
		}
		else if (position > 0) {
			size_t separator = line.find(',');
			if (separator == std::string::npos || separator + 1 >= line.length()) {
				std::cerr << "Error: línea malformada (valor faltante): '" << line << "'" << std::endl;
				continue;
			}
			if (separator == std::string::npos) {
				throw BitcoinExchange::ReadingCSV();
				return std::map<std::string, float>();
			}
			std::string date = parseDate(trim(line.substr(0, separator)));
			separator++;
			if (isspace(line[separator]))
				separator++;
			float value = toFloat(trim(line.substr(separator)));
			dbMap[date] = value;
		}
		position++;
	}
	fileContent.close();
	return dbMap;
}

std::map<std::string, float>	BitcoinExchange::loadInput()	{
	std::map<std::string, float>	inputMap;
	std::ifstream	fileContent(_inputFile.c_str());
	std::string		line;
	size_t			position = 0;

	if (!fileContent.is_open())	{
		std::cerr << "Error: could not open file." << std::endl;
		return inputMap;
	}
	while (std::getline(fileContent, line)) {
		if (line.find('\r') != std::string::npos)
			line.erase(line.find('\r'));
		line = trim(line);
		if (line.empty())
			continue;
		if (position == 0 && line == "date | value") {
			position++;
			continue;
		}
		else if (position == 0 && line != "date | value")
			throw BitcoinExchange::InvalidInput();
		if (line.find('|') == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			position++;
			continue;
		}
		size_t separator = line.find('|');
		if (separator + 1 >= line.length()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			position++;
			continue;
		}
		try {
			std::string date = parseDate(trim(line.substr(0, separator)));
			size_t valStart = separator + 1;
			while (valStart < line.length() && isspace(line[valStart]))
				valStart++;
			float value = toFloat(trim(line.substr(valStart)));
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else {
				// Buscar fecha en DB y calcular directamente (soporta duplicados)
				std::map<std::string, float>::iterator dbIt = _dbMap.lower_bound(date);
				if (dbIt == _dbMap.end() || dbIt->first != date) {
					if (dbIt == _dbMap.begin()) {
						std::cerr << "Error: no data for date " << date << std::endl;
						position++;
						continue;
					}
					--dbIt;
				}
				float result = value * dbIt->second;
				std::cout << date << " => " << value << " = "<< std::fixed << std::setprecision(2) << result << std::endl;
				inputMap[date] = value;
			}
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		position++;
	}
	fileContent.close();
	return inputMap;
}

/*	EXCEPTION	***	*/

const char	*BitcoinExchange::BitcoinExistence::what() const throw()	{
	return ("Error: Bitcoin didn't exist in this date or date is in the future.");
}

const char	*BitcoinExchange::InvalidValue::what() const throw()	{
	return ("Error: Invalid input/value.");
}

const char	*BitcoinExchange::InvalidDay::what() const throw()	{
	return ("Error: Invalid input/date/day");
}

const char	*BitcoinExchange::InvalidMonth::what() const throw()	{
	return ("Error: Invalid input/date/month");
}

const char	*BitcoinExchange::InvalidYear::what() const throw()	{
	return ("Error: Invalid input/date/year");
}

const char	*BitcoinExchange::InvalidDate::what() const throw()	{
	return ("Error: Invalid input/date/");
}

const char	*BitcoinExchange::InvalidInput::what() const throw()	{
	return ("Error: Invalid input/");
}

const char	*BitcoinExchange::ReadingInput::what() const throw()	{
	return ("Error: Reading input/");
}

const char	*BitcoinExchange::ReadingCSV::what() const throw()	{
	return ("Error: Reading CSV/");
}
