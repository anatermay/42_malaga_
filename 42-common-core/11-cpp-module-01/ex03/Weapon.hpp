/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:17:44 by aternero          #+#    #+#             */
/*   Updated: 2025/11/17 15:22:13 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

// *** LIBRARIES *** //

# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType() const;
		void				setType(std::string type);
};

// *** FUNCTIONS *** //

#endif
