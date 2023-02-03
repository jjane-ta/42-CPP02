/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Segment.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:34:39 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/03 15:44:19 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Segment.hpp"

//Segment::Segment ( void ) {}
Segment::~Segment ( void ) {}
//Segment::Segment (const Segment &segment){}
//Segment & Segment::operator = (const Segment &segment) {}

//Parametrized constructor
Segment::Segment (const Point & p1, const Point & p2, const Point & convexTo) : 
	_p1(p1),
	_p2(p2),
	_director(Vector::v_director(p1 , p2)),	
	_normal(_set_normal(convexTo))
{
	if (!_p1.good() || !_p2.good() || !_director.good() || !_normal.good())
		_error = 1;
}

Vector Segment::_set_normal( const Point & convexTo )
{	
	Vector	n = Vector::v_normal(this->_director);
	Vector	dir = Vector::v_director(this->_p1, convexTo);
	Fixed	value  = Vector::p_escalar(n, dir);
	
	this->_error = 0;
	if (value.good() && value > 0) 
		return (n);
	if (value.good() && value < 0) 
		return (Vector::v_invert(n));
	this->_error = true;
		return (Vector());
}

Fixed Segment::isLookingPoint(const Point point)
{
	Vector dir = Vector::v_director(this->_p1, point);
	return (Vector::p_escalar(this->_normal, dir));
}

bool Segment::good( void )
{
	if (this->_error)
	{
		return (false);
	}
	return (true);
}

void Segment::print( void )
{
	std::cout << "Segment info:\n\t";
	this->_p1.print();	
	std::cout << ' ';
	this->_p2.print();	
	std::cout << ' ';
	this->_director.print();	
	std::cout << ' ';
	this->_normal.print();	
	std::cout << " Error => " << std::boolalpha << !this->good();
	std::cout << std::endl;

}
