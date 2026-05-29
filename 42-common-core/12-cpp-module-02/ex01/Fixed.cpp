/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/12/02 15:20:51 by codespace        ###   ########.fr       */
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

Fixed::Fixed(const int number) : value(number << bits)
{
	std::cout << "Int constructor called" << std::endl;	
	return ;
}

/*	FIXED::FIXED(CONST INT NUMBER);

	This constructor converts a floating-point number to a fixed-point representation.
	It scales the float by 2^bits and rounds it to the nearest integer.
*/

Fixed::Fixed(const float number)
{
	this->value = round(number * (1 << this->bits));
	std::cout << "Float constructor called" << std::endl;
	return ;
}

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

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->bits));
}

/*	FLOAT FIXED::TOFLOAT(VOID);

	This function converts the fixed-point number to an integer.
	It shifts the internal value right by the number of fractional bits.
*/

int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

/*	INT FIXED::TOINT(VOID);

	This function converts the fixed-point number to an integer.
	It shifts the internal value right by the number of fractional bits.
*/

// *** OVERLOADED OPERATORS *** //

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/*	OSTREAM &OPERATOR<<(OSTREAM &OUT, CONST FIXED &FIXED);

	This overloads the insertion operator to output the fixed-point number as a float.
	It allows easy printing of Fixed objects using standard output streams.
*/
