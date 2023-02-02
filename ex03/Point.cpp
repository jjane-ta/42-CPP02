/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:01:17 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/02 18:56:48 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ( void ) : _x(0), _y(0) {}

Point::~Point ( void ) {}

Point::Point (const Point &point) : _x(point._x), _y(point._y) {}

/*
const Point & Point::operator = (const Point & point) const
{
//	(void) point;

//	point.print();
	return (point);
}
*/

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

//	a.print();
//	b.print();

//	Point((Fixed)a._x - (Fixed)b._x, (Fixed)a._y - (Fixed)b._y).print();



	return (Point((Fixed)a._x - (Fixed)b._x, (Fixed)a._y - (Fixed)b._y));
}

Vector	Vector::v_normal(const Vector & direction)
{

//	direction.print();

	
//	Point((Fixed(-1) * direction._y), direction._x).print();


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


