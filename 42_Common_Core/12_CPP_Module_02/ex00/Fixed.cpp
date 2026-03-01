/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/12/02 15:07:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// *** CONSTRUCTORS *** //

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/*	FIXED::FIXED(VOID);

	This is the copy constructor.
	It initializes a new object as a copy of an existing object.
*/

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
	return ;
}

/*	FIXED::FIXED(CONST FIXED &OTHER);

	This is the copy assignment operator.
	It assigns the values from one existing object to another existing object.
*/

// *** OPERATORS *** //

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

/*	FIXED &FIXED::OPERATOR=(CONST FIXED &OTHER);

	This is the destructor.
	It is called when an object goes out of scope or is explicitly deleted.
*/

// *** DESTRUCTOR *** //

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*	FIXED::~FIXED(VOID);

	This function returns the raw integer value of the fixed-point number.
	It allows access to the internal representation of the fixed-point number.
*/

// *** MEMBER FUNCTIONS *** //

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

/*	VOID FIXED::SETRAWBITS(INT CONST RAW);

	This function sets the raw integer value of the fixed-point number.
	It allows modification of the internal representation of the fixed-point number.
*/

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

/*	VOID FIXED::SETRAWBITS(INT CONST RAW);

	This function sets the raw integer value of the fixed-point number.
	It allows modification of the internal representation of the fixed-point number.
*/
