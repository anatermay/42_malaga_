/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2025/12/09 19:32:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// *** CONSTRUCTORS *** //

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
	return ;
}

Fixed::Fixed(const int number) : value(number << bits)
{
	std::cout << "Int constructor called" << std::endl;	
	return ;
}

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

// *** DESTRUCTOR *** //

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// *** MEMBER FUNCTIONS *** //

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

// *** OVERLOADED OPERATORS *** //

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// *** ADDITIONAL OPERATORS *** //

// Arithmetic operators
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->value - other.value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits((this->value * other.value) / (1 << this->bits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;
	long	ret;

	ret = static_cast<long>(this->value / other.value);
	result.setRawBits(ret / (1 << this->bits));
	return (result);
}

// Comparison operators
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->value > other.value ? true : false);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->value < other.value ? true : false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->value >= other.value ? true : false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->value <= other.value ? true : false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->value == other.value ? true : false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->value != other.value ? true : false);
}

// Increment/Decrement operators
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->value++;
	return (temp);
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->value--;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

// Static member functions
Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	return (a.value < b.value ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.value < b.value ? a : b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return (a.value > b.value ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.value > b.value ? a : b);
}
