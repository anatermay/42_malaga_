/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/27 19:27:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
    
// *** LIBRARIES *** //
# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain&	operator=(const Brain &other);
		~Brain();
		void			setIdea(int index, std::string text);
		std::string		getIdea(int index) const;
};

#endif
