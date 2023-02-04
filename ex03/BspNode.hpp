/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BspNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:42:00 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/04 17:00:33 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BSPNODE_H__
# define __BSPNODE_H__

# include "Segment.hpp"

// ************************************************************************** //
//                              BspNode Class                                
// ************************************************************************** //

class BspNode {

public:

	//OCCF
	~BspNode ( void );
	BspNode (const BspNode & bspnode);
	BspNode operator = (const BspNode & bspnode);
	
	//Parametrized Constructor
	BspNode (Segment **s);
	BspNode (const bool & type);
	
	bool	checkPoint(const Point & point);

private:

	//OCCF
	BspNode ( void );
	
	Segment	*node;
	Segment	**segments;
	BspNode	*front;
	BspNode	*back;
	bool	leaf;
	bool	solid;

	void	init( void );

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* __BSPNODE_H__ */


