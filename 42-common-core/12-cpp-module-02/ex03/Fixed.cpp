/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/08 13:53:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// *** CONSTRUCTORS *** //

Fixed::Fixed(void) : value(0)
{
	return ;
}

Fixed::Fixed(const Fixed &other)
{
	setRawBits(other.getRawBits());
	return ;
}

Fixed::Fixed(const int number) : value(number << bits)
{
	return ;
}

Fixed::Fixed(const float number)
{
	this->value = round(number * (1 << this->bits));
	return ;
}

// *** OPERATORS *** //

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

// *** DESTRUCTOR *** //

Fixed::~Fixed(void)
{
	return ;
}

// *** MEMBER FUNCTIONS *** //

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
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
