/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:56:08 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/04 15:15:58 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"


// ************************************************************************** //
//                              Point Class                                
// ************************************************************************** //

class Point;
typedef Point Vector;

class Point {

public:

	//OCCF
	Point ( void );
	~Point ( void );
	Point (const Point &point);
	Point operator = (const Point & point);

	// Parametrized constructor
	Point (const float x, const float y);
	Point (const Fixed & x, const Fixed & y);


	//Print
	void	print ( void ) const;

	//Director Point
	static Vector	v_director (const Point & a, const Point & b);
	static Vector	v_normal(const Vector & direction);
	static Vector	v_invert(const Vector & vector);
	static Fixed	p_escalar(const Vector & v_a, const Vector & v_b);

	//Error
	bool	good( void ) const;
	
private:
	
	const Fixed _x;
	const Fixed	_y;

};


#endif /* __POINT_H__ */


