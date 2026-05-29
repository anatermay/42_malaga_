/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:31 by aternero          #+#    #+#             */
/*   Updated: 2025/11/17 15:17:04 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

// *** DISCLAIMER *** //
/*
     --------------------------------------------------------------------------
	| Human A always has a weapon assigned upon creation. Therefore, we use a  |
	| reference to a Weapon object.                                            |
     --------------------------------------------------------------------------

	REFERENCE ------------------------------------------------------------------
	|	A reference is an alias for another variable. It must be initialized   |
	|	when it is created and cannot be changed to refer to another variable  |
	|	later. This ensures that Human A always has a valid weapon assigned    |
	|	from the moment of its creation. 								       |
	|	An example of a reference is a nickname that always refers to the same |
	|	person. Once you give someone a nickname, it will always point to that |
	|	same person and cannot be changed to refer to someone else.            |
     --------------------------------------------------------------------------
*/

// *** LIBRARIES *** //

# include <iostream>
# include <string>
# include "Weapon.hpp"

// *** CLASS DEFINITION *** //

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
};

// *** FUNCTIONS *** //

#endif