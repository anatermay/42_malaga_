/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:00 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:35:28 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <iostream>
# include <vector>

class	Span	{
	private:
		std::vector<int>	_span;
		unsigned int		_N;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span	&operator=(const Span &other);
		void	addNumber(int value);
		int		shortestSpan();
		int		longestSpan();
		class	ExceedsTheLimit : public std::exception	{
		public:
			const char *what() const throw();
			//{	return ("Error: Exceeds the limit.");	}
		};
		class	NoNumbers : public std::exception	{
		public:
			const char *what() const throw();
		};
};

#endif
