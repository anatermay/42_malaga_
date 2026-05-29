/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/12/02 15:19:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

// *** LIBRARIES *** //

# include <iostream>
# include <cmath>

// *** CLASS DEFINITION *** //

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed(const int number);
		Fixed(const float number);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

// *** FUNCTIONS *** //
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
