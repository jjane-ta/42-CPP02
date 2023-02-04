/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:01:17 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/04 17:27:51 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ( void ) : _x(0), _y(0) {}

Point::~Point ( void ) {}

Point::Point (const Point &point) : _x(point._x), _y(point._y) {}

Point	Point::operator = (const Point & point)
{
	return (Point(point));
}


// Parametrized constructor
Point::Point (const float x, const float y) : _x(x), _y(y) {}
Point::Point (const Fixed & x, const Fixed & y) : _x(x), _y(y) {}
  

// Print
void	Point::print( void ) const
{
	std::cout << "(" << this->_x << "," << this->_y << ")";
}

//director vector

Vector	Vector::v_director(const Point & a,const Point & b)
{
	return (Point((Fixed)a._x - (Fixed)b._x, (Fixed)a._y - (Fixed)b._y));
}

Vector	Vector::v_normal(const Vector & direction)
{
	return (Point((Fixed(-1) * direction._y), direction._x));
}

Vector Vector::v_invert(const Vector & vector)
{
	return (Point((Fixed(-1) * vector._x), Fixed(-1) * vector._y));
}

Fixed	Vector::p_escalar(const Vector & v_a, const Vector & v_b)
{
	return (((Fixed)v_a._x * (Fixed)v_b._x ) + ((Fixed)v_a._y * (Fixed)v_b._y));
}

bool Point::good( void ) const
{
	if (!this->_x.good() || !this->_y.good())
	{
		return (false);
	}
	return (true);
}
