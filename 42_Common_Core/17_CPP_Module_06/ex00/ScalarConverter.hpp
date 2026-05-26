/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:53:16 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 14:49:30 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cctype>
# include <cerrno>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

# define TRUE 1
# define FALSE 0
# define ERR -1

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	ERROR
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &other);
	public:
		static void	convert(const std::string &scalar);
};

#endif
