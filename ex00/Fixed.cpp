/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:51:06 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/21 19:20:20 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed ( void ) :
	_value(0)
{
	std::cout << "Default constructor called\n";
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
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
	std::cout << "setRawBits member function called\n";
}
