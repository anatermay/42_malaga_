/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:39:02 by aternero          #+#    #+#             */
/*   Updated: 2026/05/05 21:02:22 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

/*	INCLUDES	*/

# include <iostream>
# include <fstream>
# include <stack>
# include <string>

/*	CLASSES		*/

class	RPN	{
	private:
		std::stack<int>	nbr;
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN	&operator=(const RPN &other);
		void	start(const std::string &argv);
		void	calculator(char c);
		class InvalidDivision : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class InvalidNumber : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
