/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/03/01 15:18:15 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
    
// *** LIBRARIES *** //

# include "Animal.hpp"
# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &other);
		Cat&	operator=(const Cat &other);
		virtual void	makeSound() const;
		~Cat();
};

#endif
