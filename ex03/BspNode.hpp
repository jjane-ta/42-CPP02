/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BspNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:42:00 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/03 20:21:18 by jjane-ta         ###   ########.fr       */
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
	
	BspNode (Segment **s);
	BspNode (bool type);

	void	init( void );

private:

	//OCCF
	BspNode ( void );
	BspNode (const BspNode &bspnode);
	BspNode & operator = (const BspNode &bspnode);


	Segment	*node;
	Segment	**segments;
	BspNode	*front;
	BspNode	*back;
	bool	leaf;
	bool	solid;

};
#endif /* __BSPNODE_H__ */


