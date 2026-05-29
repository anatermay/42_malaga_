/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/12/01 14:28:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

// *** LIBRARIES *** //

# include <iostream>
# include <string>

// *** CLASS DEFINITION *** //

class Harl
{
	private:
		struct	_handlers
		{
			std::string	levels;
			void		(Harl::*f)( void );
		};
		_handlers	handlers[4];
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
	public:
		Harl();
		~Harl();
		void		complain( std::string level );
};

// *** ALLOWED FUNCTIONS *** //

// *** FUNCTIONS *** //

#endif
