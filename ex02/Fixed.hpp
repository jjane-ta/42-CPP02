/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:02:11 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/26 14:50:59 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>
#include <iomanip>
#include <cmath>


// ************************************************************************** //
//                              Fixed Class                                
// ************************************************************************** //

class Fixed {

public:

	//Vars
	static int	format;

	// OCCF
	Fixed ( void );
	~Fixed ( void );
	Fixed (const Fixed &fixed);
	Fixed & operator = (const Fixed &fixed);

	//Parametrized Constructors
	Fixed ( const int value );
	Fixed ( const float value );

	// LIMITS
	static float	max();
	static float	min();
	static Fixed	max(Fixed &a, Fixed &b);
	static Fixed	max(const Fixed &a, const Fixed &b);
	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	min(const Fixed &a, const Fixed &b);
	
	// RawBits manipulators
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	// Parser
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// Error
	int		good ( void ) const;
	void	clear ( void );

	// 6 comparison operators: >, <, >=, <=, == and !=
	bool operator > ( const Fixed & other ) const;
	bool operator < ( const Fixed & other ) const;
	bool operator >= ( const Fixed & other ) const;
	bool operator <= ( const Fixed & other ) const;
	bool operator == ( const Fixed & other ) const;
	bool operator != ( const Fixed & other ) const;

	// 4 arithmetic operators: +, -, *, and /
	Fixed operator + ( const Fixed & other );
	Fixed operator - ( const Fixed & other );
	Fixed operator * ( const Fixed & other );
	Fixed operator / ( const Fixed & other );

	// 4 increment/decrement
	
		//prefix
		Fixed & operator ++ ();
		Fixed & operator -- ();
		//postfix
		Fixed operator ++ (int);
		Fixed operator -- (int);

private:
	
	// Class var
	static const int	_n_fractionBits = 8;
	
	// Vars
	int					_value;
	int					_error;

	// Parser
	void	_valueToFixed(float value);
	void	_checkRawBits(long value);

};

// Overload output stream
std::ostream & operator << (std::ostream& os, const Fixed &fixed);

#endif /* __FIXED_H__ */


