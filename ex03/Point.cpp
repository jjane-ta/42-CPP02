/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:01:17 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/27 20:02:35 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ( void ) : _x(0), _y(0) {}

Point::~Point ( void ) {}

Point::Point (const Point &point) {	*this = point;}

Point & Point::operator = (const Point &point)
{
	this->_x = point._x;
	this->_y = point._y;
	return (*this);
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

Point	Point::v_director(const Point & a,const Point & b)
{
	return (Point((Fixed)a._x - (Fixed)b._x, (Fixed)a._y - (Fixed)b._y));
}

Point	Point::v_normal(const Point & direction)
{
	return (Point((Fixed(-1) * direction._y), direction._x));
}

Fixed	Point::p_escalar(const Point & v_a, const Point & v_b)
{
	return (((Fixed)v_a._x * (Fixed)v_b._x ) + ((Fixed)v_a._y * (Fixed)v_b._y));
}
