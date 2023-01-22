/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:51:06 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/22 20:39:36 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed ( void ) :
	_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed ( const int value ) : _value(value << _n_fractionBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed ( const float value ) : _value(roundf(value * ((1 << _n_fractionBits) - 1 )))
{
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
	return (roundf((float)_value / (1 << 8)));
}

int Fixed::toInt( void ) const
{
	return (_value >> 8);
}

std::ostream & operator << (std::ostream& os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}

float	Fixed::max()
{
	Fixed max_value;


	std::cout << "int max => " <<  std::numeric_limits<int>::max() << std::endl;
	max_value.setRawBits(std::numeric_limits<int>::max());

	std::cout << max_value.getRawBits() << std::endl;
	std::cout << max_value.toInt() << std::endl;
	std::cout << max_value.toFloat() << std::endl;
	std::cout << max_value << std::endl;

	return (max_value.toFloat());
}


