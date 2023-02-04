/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:14:31 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/04 17:10:09 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BspNode.hpp"

//BspNode	*bspMakeTree(Segment **s);
static Segment	**bsp_init_segments(Point const a, Point const b, Point const c);
static Segment **bsp_clean_segments(Segment **s);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool result;
		
	Segment **s = bsp_init_segments(a, b, c);
	if (!s)
	{
		std::cout << "Not a valid triangle" << std::endl;
		return (false);
	}
	if (!point.good())
	{
		std::cout << "Not a valid point" << std::endl;
		return (false);
	}
	BspNode bspTree(s);
	result = bspTree.checkPoint(point);
	bsp_clean_segments(s);
	return (result);
}


static Segment	**bsp_init_segments(Point const a, Point const b, Point const c)
{
	Segment **s = new (Segment(*[4]));
	if (!s)
		return (nullptr);	
	s[0] = new Segment(a,b,c);
	if (!s[0])
		return (nullptr);	
	s[1] = new Segment(a,c,b);
	if (!s[1])
		return (nullptr);	
	s[2] = new Segment(b,c,a);
	if (!s[2])
		return (nullptr);	
	s[3] = nullptr;
	if (!s[0]->good() || !s[1]->good() || !s[2]->good())
		return (bsp_clean_segments(s));
	return (s);
}

static Segment **bsp_clean_segments(Segment **s)
{
	int i = 0;
	while (s && s[i])
		delete s[i++];
	delete s;
	return (nullptr);
}
