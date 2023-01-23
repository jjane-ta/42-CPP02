/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:51:06 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/23 20:30:58 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed ( void ) :
	_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed ( const int value )// : _value(value << _n_fractionBits)
{
	this->valueToFixed((float)value);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed ( const float value )// : _value(roundf((double)value * (double) (1 << _n_fractionBits)))
{
	this->valueToFixed((float)value);
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed (const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed; 
}
	
Fixed & Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	_value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (_value);
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	float value = (float)_value / (1 << _n_fractionBits);
	if (value > Fixed::max())
		return (Fixed::max());
	else if (value < Fixed::min())
		return (Fixed::min());
	else
		return (value);
}

int Fixed::toInt( void ) const
{
	return (_value >> _n_fractionBits);
}

std::ostream & operator << (std::ostream& os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}

float	Fixed::max()
{
	return (INT_MAX >> _n_fractionBits);
}

float	Fixed::min()
{
	return (INT_MIN >> _n_fractionBits);
}

void	Fixed::valueToFixed(float value)
{
	if (!isfinite(value))
	{
		if (value > 0)
			this->_value = INT_MAX;
		else if (value < 0)
			this->_value = INT_MIN;
		else
			this->_value = 0.0;		
	}
	else
	{
		if (value > Fixed::max())
			this->_value = INT_MAX;
		else if (value < Fixed::min())
			this->_value = INT_MIN;
		else
			this->_value = roundf((double)value * (double) (1 << _n_fractionBits));
	}
}
