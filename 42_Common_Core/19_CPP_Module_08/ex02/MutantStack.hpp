/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:40:28 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:58:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>()	{ }
		MutantStack(const MutantStack &other) : std::stack<T>(other)	{ }
		~MutantStack()	{ }
		MutantStack	&operator=(const MutantStack &other)	{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();
};

# include "MutantStack.tpp"

#endif
