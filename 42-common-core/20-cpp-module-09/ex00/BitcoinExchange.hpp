/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:39:02 by aternero          #+#    #+#             */
/*   Updated: 2026/05/12 17:06:50 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/*	INCLUDES	*/

# include <cctype>
# include <cerrno>
# include <cstdlib>
# include <ctime>
# include <exception>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <limits>
# include <map>
# include <string>

/*	CLASSES		*/

class	BitcoinExchange	{
	private:
		std::map<std::string, float>	_inputMap;
		std::map<std::string, float>	_dbMap;
		std::string						_inputFile;
		std::string						_csvData;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &inputFile);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		std::map<std::string, float>	loadDB();
		std::map<std::string, float>	loadInput();
		std::string	parseDate(const std::string &line);

		class BitcoinExistence : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class InvalidValue : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class InvalidDay : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class InvalidMonth : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class InvalidYear : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class InvalidDate : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class InvalidInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class ReadingInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class ReadingCSV : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
