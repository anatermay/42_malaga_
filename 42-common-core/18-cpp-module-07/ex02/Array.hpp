/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:12:36 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 18:46:16 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/*	INCLUDES		*/

# include <exception>

/*	CLASSES			*/

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_n;

	public:
		Array() : _array(new T[0]), _n(0) {}
		Array(unsigned int n) : _array(new T[n]), _n(n) {}
		Array(const Array &other) : _array(new T[other._n]), _n(other._n)	{
			for (unsigned int i = 0; i < _n; ++i)
				_array[i] = other._array[i];
		}
		~Array() { delete[] _array; }

		Array &operator=(const Array &other)	{
			if (this != &other)
			{
				T *new_array = new T[other._n];
				for (unsigned int i = 0; i < other._n; ++i)
					new_array[i] = other._array[i];
				delete[] _array;
				_array = new_array;
				_n = other._n;
			}
			return (*this);
		}

		T &operator[](unsigned int index)	{
			if (index >= _n)
				throw ElementAccess();
			return (_array[index]);
		}

		const T &operator[](unsigned int index) const	{
			if (index >= _n)
				throw ElementAccess();
			return (_array[index]);
		}

		unsigned int size() const { return (_n); }

		class ElementAccess : public std::exception	{
			public:
				const char *what() const throw()	{	return ("Error: Index is out of bounds.");	}
		};
};

#endif
