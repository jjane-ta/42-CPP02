/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BspNode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:22:42 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/03 20:21:59 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BspNode.hpp"

BspNode::~BspNode ( void )
{
	if (back)
		delete back;
	if (front)
		delete front;
}

BspNode::BspNode (bool type)
{
	this->init();
	if (type)
		leaf = type;
	else
		solid = type;
}	


BspNode::BspNode (Segment **s)
{
	this->init();
	node = *s;
	segments = s++;
	back = new BspNode(solid);

	if (!segments)
	{
		leaf = true;
		front = new BspNode(leaf);
	}
	else
		front = new BspNode(segments);
}

void	BspNode::init( void )
{
	node = nullptr;
	segments = nullptr;
	front = nullptr;
	back = nullptr;
	leaf = false;
	solid = false;
}
