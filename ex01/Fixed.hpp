/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:02:11 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/24 15:39:50 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

#include <iostream>
#include <cmath>


// ************************************************************************** //
//                              Fixed Class                                
// ************************************************************************** //

class Fixed {

public:

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
	
	// RawBits manipulators
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	// Parser
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// Error
	int		good ( void ) const;
	void	clear ( void );

private:
	
	// Class var
	static const int	_n_fractionBits = 8;

	// Vars
	int					_value;
	int					_error;

	// Parser
	void	_valueToFixed(float value);

};

// Overload output stream
std::ostream & operator << (std::ostream& os, const Fixed &fixed);

#endif /* __FIXED_H__ */


