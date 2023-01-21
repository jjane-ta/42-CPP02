/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:02:11 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/21 19:20:39 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__


// ************************************************************************** //
//                              Fixed Class                                
// ************************************************************************** //

class Fixed {

public:

	Fixed ( void );
	~Fixed ( void );
	Fixed (const Fixed &fixed);
	Fixed & operator = (const Fixed &fixed);

	int getRawBits( void ) const;
	void setRawBits( int const raw );


private:

	int	_value;
	static const int _n_fractionBits = 8;

};
#endif /* __FIXED_H__ */


