/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:22 by aternero          #+#    #+#             */
/*   Updated: 2026/01/08 14:13:11 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

static float	triangleArea(Point const a, Point const b, Point const c)
{
	float	calc[3];
	float	area;

	calc[0] = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
	calc[1] = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
	calc[2] = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());
	area = calc[0] + calc[1] + calc[2];
	if (area < 0)
		area *= -1;
	area /= 2;
	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	check[3];
	float	area;
	float	sum;

	area = triangleArea(a, b, c);
	if (roundf(area * 1000) <= 0)
		return (false);
	check[0] = triangleArea(point, a, b);
	if (roundf(check[0] * 1000) <= 0)
		return (false);
	check[1] = triangleArea(point, b, c);
	if (roundf(check[1] * 1000) <= 0)
		return (false);
	check[2] = triangleArea(point, c, a);
	if (roundf(check[2] * 1000) <= 0)
		return (false);
	sum = check[0] + check[1] + check[2];
	if (roundf(sum * 100) == roundf(area * 100))
		return (true);
	return (false);
}
