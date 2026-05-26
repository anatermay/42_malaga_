/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:26:39 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 14:04:19 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

/*	INCLUDES		*/

# include <iostream>
# include <cstdlib>

/*	UTILS FUNCTIONS	*/

template <typename T>
void	plusOne(T &out)	{
	out++;
}

template <typename T>
void	printValue(T const &out)	{
	std::cout << out << std::endl;
}

/*	MAIN FUNCTIONS	*/

template <typename T>
void	iter(T *array, size_t length, void (*f)(T&))	{

	if (!array || !f)
		return ;
	for (size_t index = 0; index < length; index++)
		f(array[index]);
}

template <typename T>
void	iter(const T *array, size_t length, void (*f)(const T&))	{

	if (!array || !f)
		return ;
	for (size_t index = 0; index < length; index++)
		f(array[index]);
}

/*	··· ··· ···		*/

#endif
