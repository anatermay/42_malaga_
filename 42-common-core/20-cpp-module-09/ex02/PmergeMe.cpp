/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PmergeMe2.cpp									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aternero <aternero@student.42malaga.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/04/28 19:39:52 by aternero		  #+#	#+#			 */
/*   Updated: 2026/05/11 20:40:03 by aternero		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <functional>

/* ====================== DEQUE IMPLEMENTATION ====================== */


void	PmergeMe::sortDeque()	{
	if (myDeque.size() <= 1)
		return ;

	std::deque<int>	bigger;
	std::deque<int>	lower;

	// 1. Separar en parejas (makePairList)
	for (size_t index = 0; index + 1 < myDeque.size(); index += 2)	{
		if (myDeque[index] > myDeque[index + 1])	{
			bigger.push_back(myDeque[index]);
			lower.push_back(myDeque[index + 1]);
		}
		else	{
			bigger.push_back(myDeque[index + 1]);
			lower.push_back(myDeque[index]);
		}
	}
	if (myDeque.size() % 2 != 0)
		lower.push_back(myDeque.back());

	// 2. Llamada recursiva con los mayores
	myDeque = bigger;
	sortDeque();
	bigger = myDeque;

	// 3. Inserción del primer elemento de los menores
	if (!lower.empty()) {
		int first = lower[0];
		std::deque<int>::iterator pos = std::lower_bound(myDeque.begin(), myDeque.end(), first);
		myDeque.insert(pos, first);
	}

	// 4. Inserción con Jacobsthal
	size_t index = 1;
	size_t j = 1;

	while (index < lower.size())
	{
		size_t next = jacobsthal(j++);
		size_t limit = (next < lower.size()) ? next : lower.size();

		for (; index < limit; ++index)
		{
			int value = lower[index];
			std::deque<int>::iterator pos = std::lower_bound(myDeque.begin(), myDeque.end(), value);
			myDeque.insert(pos, value);
		}
	}
}

/* ====================== EXCEPTIONS ====================== */

const char	*PmergeMe::InvalidInput::what() const throw()	{	return ("Error: Invalid input.");	}

const char	*PmergeMe::NegativeNumber::what() const throw()	{	return ("Error: Negative numbers are forbidden.");	}

/* ====================== JACOBSTHAL ====================== */

std::size_t PmergeMe::jacobsthal(size_t nbr) {
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	size_t a = 0, b = 1, c;
	for (size_t index = 2; index <= nbr; ++index) {
		c = b + 2 * a;
		a = b;
		b = c;
	}
	return (b);
}

/* ====================== ORTHODOX CANONICAL FORM ====================== */

PmergeMe::PmergeMe() : _timeDeque(0), _timeVector(0)	{   }

PmergeMe::PmergeMe(const PmergeMe &other) : _original(other._original), myDeque(other.myDeque), myVector(other.myVector), _timeDeque(other._timeDeque), _timeVector(other._timeVector)   {   }

PmergeMe::~PmergeMe()   {   }

PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {

	if (this != &other) {
		_original = other._original;
		myDeque = other.myDeque;
		myVector = other.myVector;
		_timeDeque = other._timeDeque;
		_timeVector = other._timeVector;
	}
	return (*this);
}

/* ====================== UTILS ====================== */

int	ftStoi(const char *str)	{
	int	index = 0;
	int	nbr = 0;

	if (!str || str[index] == '\0')
		throw PmergeMe::InvalidInput();
	while (str[index] == 32 || (str[index] > 9 && str[index] < 13))
		index++;
	if (str[index] == '-')
		throw PmergeMe::NegativeNumber();
	if (str[index] == '+')
		index++;
	while (str[index] >= 48 && str[index] <= 57)	{
		nbr = (nbr * 10) + (str[index] - '0');
		index++;
	}
	if (str[index] != '\0')
		throw PmergeMe::InvalidInput();
	return (nbr);
}

void	PmergeMe::fill(int argc, char **argv)   {
	for (int yndex = 1; yndex < argc; yndex++)	{
		try {
			int	nbr = ftStoi(argv[yndex]);
			_original.push_back(nbr);
			myVector.push_back(nbr);
			myDeque.push_back(nbr);
		}
		catch(const std::exception& e)	{	std::cerr << e.what() << '\n';	return ;	}
	}
}

void	PmergeMe::sort()	{
	struct timeval	startVector;
	struct timeval	endVector;
	struct timeval	startDeque;
	struct timeval	endDeque;

	gettimeofday(&startVector, NULL);
	sortVector();
	gettimeofday(&endVector, NULL);
	_timeVector = (endVector.tv_sec - startVector.tv_sec) * 1000000.0
		+ (endVector.tv_usec - startVector.tv_usec);

	gettimeofday(&startDeque, NULL);
	sortDeque();
	gettimeofday(&endDeque, NULL);
	_timeDeque = (endDeque.tv_sec - startDeque.tv_sec) * 1000000.0
		+ (endDeque.tv_usec - startDeque.tv_usec);
}

void	PmergeMe::display() const   {
	std::cout << "Before:";
	for (size_t index = 0; index < _original.size(); index++)
		std::cout << " " << _original[index];
	std::cout << std::endl;

	std::cout << "After:";
	for (size_t index = 0; index < myVector.size(); index++)
		std::cout << " " << myVector[index];
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector : " << _timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque : " << _timeDeque << " us" << std::endl;
}

/* ====================== VECTOR IMPLEMENTATION ====================== */

void	PmergeMe::sortVector()	{
	if (myVector.size() <= 1)
		return ;

	std::vector<int>	bigger;
	std::vector<int>	lower;

	// 1. Separar en parejas
	for (size_t index = 0; index + 1 < myVector.size(); index += 2)	{
		if (myVector[index] > myVector[index + 1])	{
			bigger.push_back(myVector[index]);
			lower.push_back(myVector[index + 1]);
		}
		else	{
			bigger.push_back(myVector[index + 1]);
			lower.push_back(myVector[index]);
		}
	}
	if (myVector.size() % 2 != 0)
		lower.push_back(myVector.back());

	// 2. Llamada recursiva con los mayores
	myVector = bigger;
	sortVector();
	bigger = myVector;

	// 3. Inserción del primer elemento de los menores
	if (!lower.empty()) {
		int first = lower[0];
		std::vector<int>::iterator pos = std::lower_bound(myVector.begin(), myVector.end(), first);
		myVector.insert(pos, first);
	}

	// 4. Inserción con Jacobsthal
	size_t index = 1;
	size_t j = 1;

	while (index < lower.size())
	{
		size_t next = jacobsthal(j++);
		size_t limit = (next < lower.size()) ? next : lower.size();

		for (; index < limit; ++index)
		{
			int value = lower[index];
			std::vector<int>::iterator pos = std::lower_bound(myVector.begin(), myVector.end(), value);
			myVector.insert(pos, value);
		}
	}
}

/* ======================						====================== */
/* ====================== THIS IS THE END OF US ====================== */
/* ======================						====================== */
