/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BspNode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:22:42 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/05 15:54:48 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BspNode.hpp"

# define DEBUG 1

BspNode::BspNode( void )
{
	BspNode::init();
}

BspNode::BspNode(const BspNode &bspnode)
{
	*this = bspnode;
}
BspNode BspNode::operator = (const BspNode &bspnode)
{
	node = bspnode.node;
	segments = bspnode.segments;
	front = bspnode.front;
	back = bspnode.back;
	leaf = bspnode.leaf;
	solid = bspnode.solid;
	return (*this);
}

BspNode::~BspNode ( void )
{
	if (back)
		delete back;
	if (front)
		delete front;
}

BspNode::BspNode (const bool & type)
{
	
	this->init();
	if (type)
	{
		if (DEBUG)
			std::cout << "LEAF\n";
		leaf = true;
	}
	else
	{
		if (DEBUG)
			std::cout << "SOLID\n";
		solid = true;
	}	
}	

BspNode::BspNode (Segment **s)
{
	this->init();
	node = *s;
	if (DEBUG)
	{
		node->print();
		std::cout << "back => ";
	}
	segments = &s[1];
	back = new BspNode(false);
	if (DEBUG)
		std::cout << "front => ";
	if (!*segments)
		front = new BspNode(true);
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

bool BspNode::checkPoint(const Point & point)
{
	Fixed value;

	if (this->leaf)
	{
		if (DEBUG)
			std::cout << "Inside\n";
		return (true);
	}
	if (this->solid)
	{
		if (DEBUG)
			std::cout << "Outside\n";
		return (false);
	}
		value = this->node->isLookingPoint(point);
	if (value > 0)
	{
		if (DEBUG)
			std::cout << "front -> ";
		return(this->front->checkPoint(point));
	}
	else if (value < 0)
	{
		if (DEBUG)
			std::cout << "back -> ";
		return (this->back->checkPoint(point));
	}
	else
	{
		if (DEBUG)
			std::cout << "Is on Edge\n";
		return (false);

	}
}
