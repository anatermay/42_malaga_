/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/27 19:22:31 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
    
// *** LIBRARIES *** //

# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &other);
		Animal&	operator=(const Animal &other);
		virtual ~Animal();
		std::string	getType() const;
		virtual void	makeSound() const;
};

#endif
