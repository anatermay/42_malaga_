/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PmergeMe.hpp									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aternero <aternero@student.42malaga.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/04/28 19:39:02 by aternero		  #+#	#+#			 */
/*   Updated: 2026/05/11 20:41:40 by aternero		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/*	INCLUDES	*/

# include <cctype>
# include <cstdlib>
# include <ctime>
# include <deque>
# include <exception>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <sys/time.h>
# include <vector>

/*	CLASSES		*/

class   PmergeMe	{
	private:
		std::vector<int>	_original;
		std::deque<int>		myDeque;
		std::vector<int>	myVector;
		double				_timeDeque;
		double				_timeVector;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &other);
		void		fill(int argc, char **argv);
		void		display() const;
		void		sort();
		std::size_t jacobsthal(size_t nbr);

		// Para vector
		void	sortVector();

		// Para deque
		void	sortDeque();

		class InvalidInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class NegativeNumber : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

/*	FUNCTIONS	*/

int	ftStoi(const char *str);

#endif
