/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:56:08 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/27 19:57:42 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

// ************************************************************************** //
//                              Point Class                                
// ************************************************************************** //

class Point {

public:

	//OCCF
	Point ( void );
	~Point ( void );
	Point (const Point &point);
	Point & operator = (const Point &point);

	// Parametrized constructor
	Point (const float x, const float y);
	Point (const Fixed & x, const Fixed & y);

	//Print
	void	print ( void ) const;

	//Director Point
	static Point v_director (const Point & a, const Point & b);
	static Point v_normal(const Point & direction);
	static Fixed p_escalar(const Point & v_a, const Point & v_b);
	
private:

	Fixed _x;
	Fixed _y;


};

#endif /* __POINT_H__ */


