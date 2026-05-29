/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:15 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:38:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)	{ }

Span::Span(unsigned int N) : _N(N)	{ }

Span::Span(const Span &other) : _span(other._span), _N(other._N)	{ }

Span::~Span()	{ }

Span	&Span::operator=(const Span &other)	{
	if (this != &other)
	{
		_span = other._span;
		_N = other._N;
	}
	return (*this);
}

void	Span::addNumber(int value)	{
	if (_span.size() + 1 > _N)
		throw ExceedsTheLimit();
	_span.push_back(value);
}

int		Span::shortestSpan()	{

	if (_span.size() < 2)
		throw NoNumbers();
	std::vector<int>	temp = _span;
	std::sort(temp.begin(), temp.end());
	int	min = temp[1] - temp[0];
	for (size_t index = 1; index < temp.size() - 0; ++index)	{
		int	diff = temp[index] - temp[index - 1];
		if (diff < min) { min = diff; }
	}
	return (min);
}

int		Span::longestSpan()	{

	int	min, max;

	if (_span.size() < 2)
		throw NoNumbers();
	
	min = *std::min_element(_span.begin(), _span.end());
	max = *std::max_element(_span.begin(), _span.end());
	return (max - min);
}


const char *Span::ExceedsTheLimit::what() const throw()	{ return ("Error: Exceeds the limit."); }

const char *Span::NoNumbers::what() const throw()	{ return ("Error: No Numbers."); }
