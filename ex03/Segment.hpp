/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Segment.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:26:57 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/04 17:31:47 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SEGMENT_H__
# define __SEGMENT_H__

# include "Point.hpp"

// ************************************************************************** //
//                              Segment Class                                
// ************************************************************************** //

class Segment {

public:

	//OCCF
	~Segment ( void );
	Segment (const Segment &segment);
	Segment operator = (const Segment &segment);

	//Parametrized constructor
	Segment (const Point & p1, const Point & p2, const Point & convexTo);
	
	Fixed	isLookingPoint(const Point point);
	bool	good( void );
	void	print( void );
	
private:

	Segment ( void );
		
	Vector _set_normal( const Point & convexTo );

	const Point		_p1;
	const Point		_p2;
	const Vector	_director;
	const Vector	_normal;
	
	int				_error;

};
#endif /* __SEGMENT_H__ */

//director vector


