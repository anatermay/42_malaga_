/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/27 18:32:27 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
    
// *** LIBRARIES *** //

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &other);
		WrongCat&	operator=(const WrongCat &other);
		~WrongCat();
		void	makeSound() const;
};

#endif
