/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/07 14:58:45 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::~Point()
{
	;
}

Fixed	Point::getX() const
{
	return (x);
}

Fixed	Point::getY() const
{
	return (y);
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	;
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::Point(float x, float y) : x(x), y(y)
{
	;
}

Point::Point() : x(0), y(0)
{
	;
}
