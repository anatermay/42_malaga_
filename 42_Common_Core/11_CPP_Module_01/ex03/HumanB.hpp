/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:17:15 by aternero          #+#    #+#             */
/*   Updated: 2025/11/17 15:18:12 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

// *** DISCLAIMER *** //
/*
     --------------------------------------------------------------------------
	| Human B can be created without a weapon assigned. Therefore, we use a    |
	| pointer to a Weapon object.                                              |
     --------------------------------------------------------------------------

	POINTER -------------------------------------------------------------------
	|	A pointer is a variable that stores the memory address of another      |
	|	variable. It can be reassigned to point to different variables during  |
	|	its lifetime. This allows Human B to start without a weapon (nullptr)  |
	|	and later be assigned one.                                             |
	|	An example of a pointer is a post-it note that tells you where to find |
	|	something else. You can change the note on the post-it to point to     |
	|	different things as needed. Also, the post-it can indicate that there  |
	|	is nothing to point to (nullptr). Anyway, you always have to follow the|
	|	address on the post-it to find the actual item.                        |
	 --------------------------------------------------------------------------
*/

// *** LIBRARIES *** //

# include <iostream>
# include <string>
# include "Weapon.hpp"

// *** CLASS DEFINITION *** //

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		void		attack();
		void		setWeapon(Weapon &weapon);
		~HumanB();
}	;


// *** FUNCTIONS *** //

#endif
