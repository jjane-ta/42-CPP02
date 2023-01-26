/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:51:06 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/26 18:57:28 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Initial format
int Fixed::format = 0;

// OCCF
Fixed::Fixed ( void ) :
	_value(0),
	_error(0)
{
	
	//std::cout << "Default constructor called\n";
}

Fixed::~Fixed ( void )
{
	//std::cout << "Destructor called\n";
}

Fixed::Fixed (const Fixed &fixed)
{
	//std::cout << "Copy constructor called\n";
	*this = fixed; 
}
	
Fixed & Fixed::operator = (const Fixed &fixed)
{
	//std::cout << "Copy assignment operator called\n";
	_value = fixed.getRawBits();
	_error = fixed._error;
	return (*this);
}

// Parametrized Constructor

Fixed::Fixed ( const int value )
{
	this->_valueToFixed((float)value);
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed ( const float value )
{
	this->_valueToFixed((float)value);
	//std::cout << "Float constructor called\n";
}

// RawBits Manipulators

int Fixed::getRawBits( void ) const
{
	return (_value);
}

void Fixed::setRawBits( int const raw )
{

//	std::cout << "\n raw = " << raw << std::endl;
	this->_value = raw;
}

//Parser

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

int	Fixed::toInt( void ) const
{
	return (_value >> _n_fractionBits);
}

void	Fixed::_valueToFixed(float value)
{
	_error = 1;
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
		{
			this->_value = roundf((double)value * (double) (1 << _n_fractionBits));
			_error = 0;
		}
	}
}

void	Fixed::_checkRawBits(long value)
{
	_error = 1;
	if (value > (long)INT_MAX)
		this->_value = INT_MAX;
	else if (value < (long)INT_MIN)
		this->_value = INT_MIN;
	else
	{
		this->_value = value;
		_error = 0;
	}
}

// Limits

float	Fixed::max()
{
	return (INT_MAX >> _n_fractionBits);
}

float	Fixed::min()
{
	return (INT_MIN >> _n_fractionBits);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	std::cout << "REF";

	if (a >= b)
		return (a);
	return (b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b)
{
	std::cout << "CONST REF";
	if (a >= b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	std::cout << "REF";

	if (a <= b)
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b)
{
	std::cout << "CONST REF";
	if (a <= b)
		return (a);
	return (b);
}

// Error

int	Fixed::good ( void ) const
{
	if (this->_error)
		return (0);
	return (1);
}

void	Fixed::clear( void )
{
	this->_error = 0;
}

// 6 comparison operators: >, <, >=, <=, == and !=

bool Fixed::operator > ( const Fixed & other ) const
{
	if (this->_error || other._error)
		return (false);
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator < ( const Fixed & other ) const
{
	if (this->_error || other._error)
		return (false);
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator >= ( const Fixed & other ) const
{
	if (this->_error || other._error)
		return (false);
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool  Fixed::operator <= ( const Fixed & other ) const
{
	if (this->_error || other._error)
		return (false);
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool  Fixed::operator == ( const Fixed & other ) const
{
	if (this->_error || other._error)
		return (false);
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool  Fixed::operator != ( const Fixed & other ) const
{
	if (this->_error || other._error)
		return (false);
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

// 4 arithmetic operators: +, -, *, and /

Fixed Fixed::operator + ( const Fixed & other )
{
	Fixed	c;
	long	raw_result = (long) this->getRawBits() + (long) other.getRawBits();
	c._checkRawBits(raw_result);
	if (this->_error || other._error)
		c._error = 1;
	return (c);
}

Fixed Fixed::operator - ( const Fixed & other)
{
	Fixed	c;
	long	raw_result = (long) this->getRawBits() - (long) other.getRawBits();
	
	c._checkRawBits(raw_result);
	if (this->_error + other._error)
		c._error = 1;
	return (c);
}

Fixed Fixed::operator * ( const Fixed & other )
{
	Fixed	c;
	
	long	raw_result = ((long) this->getRawBits() * (long) other.getRawBits()) / (1 << _n_fractionBits);
	c._checkRawBits(raw_result);
	if (this->_error || other._error)
		c._error = 1;
	return (c);

}

Fixed Fixed::operator / ( const Fixed & other )
{
	Fixed	c;
	long	raw_result;

	if (!other.getRawBits())
		c = 0.0f/0.0f;
	else
	{
		raw_result = ((long) this->getRawBits() / (long) other.getRawBits()) * (1 << _n_fractionBits);
		c._checkRawBits(raw_result);
	}
	if (this->_error || other._error)
		c._error = 1;
	return (c);
}

// 4 increment/decrement
//prefix
Fixed & Fixed::operator ++ ()
{
	Fixed increment;

	increment.setRawBits(1);
	*this = *this + increment;
	return ( *this );
}

Fixed & Fixed::operator -- ()
{
	Fixed increment;
	
	increment.setRawBits(1);
	*this = *this - increment;
	return ( *this );
}	

//postfix
Fixed Fixed::operator ++ (int)
{
	Fixed old(*this);
	this->operator++();
	return (old);
}

Fixed Fixed::operator -- (int)
{
	Fixed old(*this);
	this->operator--();
	return (old);
}

// Overload stream output

std::ostream & operator << (std::ostream& os, const Fixed &fixed)
{
	if (Fixed::format)
	{
	 	std::cout << std::fixed;
		return (os << std::setw(15) << std::setfill(' ') << fixed.toFloat());
	}
	return (os << fixed.toFloat());
}

