/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:02:11 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/23 19:18:43 by jjane-ta         ###   ########.fr       */
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

	Fixed ( void );
	~Fixed ( void );
	Fixed (const Fixed &fixed);
	Fixed & operator = (const Fixed &fixed);

	Fixed ( const int value );
	Fixed ( const float value );


	static float	max();
	static float	min();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int					_value;
	static const int	_n_fractionBits = 8;
	
	void valueToFixed(float value);

};

std::ostream & operator << (std::ostream& os, const Fixed &fixed);

#endif /* __FIXED_H__ */


