/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:40:57 by aternero          #+#    #+#             */
/*   Updated: 2026/05/05 21:01:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*	CLASSESS		*/

RPN::RPN()	{	}

RPN::RPN(const RPN &other) : nbr(other.nbr)	{	}

RPN::~RPN()	{	}

RPN	&RPN::operator=(const RPN &other)	{
	if (this != &other)
		nbr = other.nbr;
	return (*this);
}

const char	*RPN::InvalidDivision::what() const throw()	{	return ("Error: Division by zero is not allowed.");	}

const char	*RPN::InvalidNumber::what() const throw()	{	return ("Error: Invalid input.");	}

/*	IMPLEMENTATION	*/

bool	isOperator(char c)	{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

void	RPN::calculator(char c)	{
	int	a;
	int	b;
	int	ret;

	if (nbr.size() < 2)
		throw InvalidNumber();
	b = nbr.top();
	nbr.pop();
	a = nbr.top();
	nbr.pop();
	if (c == '+')
		ret = a + b;
	else if (c == '-')
		ret = a - b;
	else if (c == '*')
		ret = a * b;
	else if (c == '/')	{
		if (b == 0)
			throw InvalidDivision();
		else
			ret = a / b;
	}
	nbr.push(ret);
}

void	RPN::start(const std::string &argv)	{

	size_t			index = 0;

	while (index < argv.length())	{
//	    std::cout << "index: " << index << " char: " << argv[index] << std::endl;
		if (isspace(argv[index]))
			index++;
		else if (isdigit(argv[index]))	{
			nbr.push(argv[index] - '0');
			index++;
		}
		else if (isOperator(argv[index]))	{
			calculator(argv[index]);
			index++;
		}
		else
			throw InvalidNumber();
	}
	if (nbr.size() != 1)
		throw InvalidNumber();
	std::cout << nbr.top() << std::endl;
}
