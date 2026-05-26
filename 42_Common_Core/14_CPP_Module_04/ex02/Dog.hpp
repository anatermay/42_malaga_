/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/27 19:52:41 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
    
// *** LIBRARIES *** //

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &other);
		Dog&	operator=(const Dog &other);
		virtual void	makeSound() const;
		virtual ~Dog();
		Brain	*getBrain() const;
};

#endif
