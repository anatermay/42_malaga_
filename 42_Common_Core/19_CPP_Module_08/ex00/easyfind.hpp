/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:31 by aternero          #+#    #+#             */
/*   Updated: 2026/04/25 21:01:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class ElementAccess : public std::exception	{
	public:
		const char *what() const throw()	{	return ("Error: Occurrence not found.");	}
};

# include "easyfind.tpp"

#endif
