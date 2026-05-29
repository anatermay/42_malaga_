/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:18:30 by aternero          #+#    #+#             */
/*   Updated: 2026/04/22 20:48:06 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	isValidPseudo(const std::string &scalar) {
	
	if (scalar == "nan" || scalar == "nanf" || scalar == "+inf" || scalar == "-inf" || scalar == "+inff" || scalar == "-inff") {return (TRUE); }
	return (FALSE);
}

long	ft_atol(const std::string &str) {
	long	index = 0, nbr = 0, sign = 1;

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

int	possibleInt(const std::string &str) {
	char *end = NULL;
	errno = 0;
	long parsed = std::strtol(str.c_str(), &end, 10);
	
	if (*end == '\0' && errno != ERANGE) {
		if (parsed >= std::numeric_limits<int>::min() && parsed <= std::numeric_limits<int>::max())
			return (TRUE);
	}
	return (FALSE);
}

void	returnFloatPseudo(const std::string &scalar) {
	std::string	print = scalar.substr(0, scalar.length() - 1);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << scalar << std::endl;
	std::cout << "double: " << print << std::endl;
}

void	returnDoublePseudo(const std::string &scalar)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << scalar << "f" << std::endl;
	std::cout << "double: " << scalar << std::endl;
}

void	returnFloat(const std::string &scalar) {
	if (isValidPseudo(scalar) == TRUE) {
		returnFloatPseudo(scalar); return ;
	}
	char	*end; double	nbr = strtod(scalar.c_str(), &end); char	c = static_cast<char>(nbr); int	decimals = 0;

	if (nbr == nbr && nbr != std::numeric_limits<double>::infinity() && nbr != -std::numeric_limits<double>::infinity() && nbr >= std::numeric_limits<int>::min() && nbr <= std::numeric_limits<int>::max()) {
		if (nbr >= 0) {
			if (!isascii(c))
				std::cout << "char: impossible" << std::endl;
			else if (isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (scalar == "0" || scalar == "-0")
			std::cout << "int: 0" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	for (size_t index = scalar.find_first_of('.'); index < scalar.length(); ++index) {
		if (scalar[index] == '0')
			break ;
		decimals++;
	}
	if (scalar == "0.0f" || scalar == "-0.0f") {
		std::cout << "float: 0.0f" << std::endl; std::cout << "double: 0.0" << std::endl;
	}
	else if (decimals <= 1)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << nbr << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(2) << nbr << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << nbr << std::endl;
	}
}

void	returnDouble(const std::string &scalar) {
	if (isValidPseudo(scalar) == TRUE) { returnDoublePseudo(scalar); return ; }
	char	*end;
	double	nbr = strtod(scalar.c_str(), &end);
	char	c = static_cast<char>(nbr);
	int		decimals = 0;

	if (nbr == nbr && nbr != std::numeric_limits<double>::infinity() && nbr != -std::numeric_limits<double>::infinity() && nbr >= std::numeric_limits<int>::min() && nbr <= std::numeric_limits<int>::max())
	{
		if (nbr >= 0) {
			if (!isascii(c)) { std::cout << "char: impossible" << std::endl; }
			else if (isprint(c)) { std::cout << "char: '" << c << "'" << std::endl; }
			else { std::cout << "char: Non displayable" << std::endl; }
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (scalar == "0" || scalar == "-0")
			std::cout << "int: 0" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	for (size_t index = scalar.find_first_of('.'); index < scalar.length(); ++index)
	{
		if (scalar[index] == '0')
			break ;
		decimals++;
	}
	if (scalar == "0.0" || scalar == "-0.0")
	{
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
	}
	else if (decimals <= 1)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << nbr << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(2) << nbr << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2) << nbr << std::endl;
	}
}

void	returnInt(const std::string &scalar)
{
	long	nbr = ft_atol(scalar);
	char	c = static_cast<char>(nbr);

	if (possibleInt(scalar) == TRUE)
	{
		if (nbr >= 0)
		{
			if (!isascii(c))
				std::cout << "char: impossible" << std::endl;
			else if (isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << nbr << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << nbr << ".0f" << std::endl;
	std::cout << "double: " << nbr << ".0" << std::endl;
}

void	returnChar(const std::string &scalar)
{
	if (!isascii(scalar[0]))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(scalar[0]))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(scalar[0]) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(scalar[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(scalar[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(scalar[0]) << ".0" << std::endl;
}

int	charCounter(const std::string &str, char c) {
	int	counter = 0;

	for (size_t index = 0; index < str.length(); index++) {
		if (str[index] == c)
			counter++;
	}
	return (counter);
}

int	isValidFloat(const std::string &scalar)
{
	if (scalar == "nanf" || scalar == "+inff" || scalar == "-inff")
		return (TRUE);
	size_t	index = 0;
	if (scalar[index] == '-' || scalar[index] == '+')
		index++;
	if (!isdigit(scalar[index]))
		return (FALSE);
	if (charCounter(scalar, 'f') != 1)
		return (FALSE);
	if (charCounter(scalar, 'f') == 1 && scalar.find_first_of('f') != scalar.length() - 1)
		return (FALSE);
	if (charCounter(scalar, '.') != 1)
		return (FALSE);
	if (charCounter(scalar, '.') == 1 && (scalar.find_first_of('.') == 0 && scalar.find_first_of('.') == scalar.length() - 1))
		return (FALSE);
	for (size_t index = 0; index < scalar.length(); index++)
	{
		if (!isdigit(scalar[index]) && index == 0 && (scalar[index] != '-' && scalar[index] != '+') && scalar[index] != '.' && scalar[index] != 'f')
			return (FALSE);
		if (!isdigit(scalar[index]) && index > 0)
		{
			if (scalar[index] == '.' && index > 0 && index < scalar.length() - 1)
			{
				if (!isdigit(scalar[index - 1]) && !isdigit(scalar[index + 1]))
					return (FALSE);
			}
			else if (scalar[index] == '.' && (index == scalar.length() - 1 || index == 0))
				return (FALSE);
			else if (scalar[index] == 'f' && (index != scalar.length() - 1 || !isdigit(scalar[index - 1])))
					return (FALSE);
			else if (scalar[index] != '.' && scalar[index] != 'f')
				return (FALSE);
		}
	}
	return (TRUE);
}

int	isValidDouble(const std::string &scalar)
{
	if (scalar == "nan" || scalar == "+inf" || scalar == "-inf")
		return (TRUE);
	size_t	index = 0;
	if (scalar[index] == '-' || scalar[index] == '+')
		index++;
	if (!isdigit(scalar[index]))
		return (FALSE);
	if (charCounter(scalar, 'f') > 0)
		return (FALSE);
	if (charCounter(scalar, '.') != 1)
		return (FALSE);
	if (charCounter(scalar, '.') == 1 && (scalar.find_first_of('.') == 0 && scalar.find_first_of('.') == scalar.length() - 1))
		return (FALSE);
	for (size_t index = 0; index < scalar.length(); index++)
	{
		if (!isdigit(scalar[index]) && index == 0 && scalar[index] != '-' && scalar[index] != '+' && scalar[index] != '.')
			return (FALSE);
		if (!isdigit(scalar[index]) && index > 0)
		{
			if (scalar[index] == '.' && index > 0 && index < scalar.length() - 1)
			{
				if (!isdigit(scalar[index - 1]) && !isdigit(scalar[index + 1]))
					return (FALSE);
			}
			else if (scalar[index] == '.' && (index == scalar.length() - 1 || index == 0))
				return (FALSE);
			else
				return (FALSE);
		}
	}
	return (TRUE);
}

int	isValidInt(const std::string &scalar) {
	
	for (size_t index = 0; index < scalar.length(); index++) {
		
		if (!isdigit(scalar[index]) && index == 0 && scalar[index] != '-' && scalar[index] != '+')
			return (FALSE);
		if (!isdigit(scalar[index]) && index > 0)
			return (FALSE);
	}
	return (TRUE);
}

int	isValidChar(const std::string &scalar) {
	
	if (scalar.length() == 1 && !isdigit(scalar[0]))
			return (TRUE);
	return (FALSE);
}

Type	getType(const std::string &scalar) {
	
	if (isValidChar(scalar) == TRUE)
		return (CHAR);
	else if (isValidInt(scalar) == TRUE)
		return (INT);
	else if (isValidFloat(scalar) == TRUE)
		return (FLOAT);
	else if (isValidDouble(scalar) == TRUE)
		return (DOUBLE);
	return (ERROR);
}

void	ScalarConverter::convert(const std::string &scalar) {
	
	if (scalar[0] == '\0') {
		std::cout << "Error: Invalid Input" << std::endl;
		return ;
	}
	Type	type = getType(scalar);

	switch (type) {
		
		case CHAR:
			returnChar(scalar); break;
		case INT:
			returnInt(scalar); break;
		case DOUBLE:	
			if (isValidPseudo(scalar) == TRUE)
				returnDoublePseudo(scalar);
			else
				returnDouble(scalar);
			break;
		case FLOAT:
			if (isValidPseudo(scalar) == TRUE)
				returnFloatPseudo(scalar);
			else
				returnFloat(scalar);
			break;
		default:
			std::cout << "Error: Invalid Input" << std::endl; break;
	}
}
