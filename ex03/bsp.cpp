/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:14:31 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/05 19:48:57 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BspNode.hpp"

//BspNode	*bspMakeTree(Segment **s);
static Segment	**bsp_init_segments(Point const a, Point const b, Point const c);
static Segment **bsp_clean_segments(Segment **s);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool result;
	Segment **s;
 
	if (!point.good())
	{
		std::cout << "Not a valid point" << std::endl;
		return (false);
	}
	s = bsp_init_segments(a, b, c);
	if (!s)
	{
		std::cout << "Not a valid triangle" << std::endl;
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
	s[1] = new Segment(a,c,b);
	s[2] = new Segment(b,c,a);
	s[3] = nullptr;
	if (!s[0] || !s[1] || !s[2])
	{
		if (s[0])
			delete s[0];
		if (s[1])
			delete s[1];
		if (s[2])
			delete s[2];
		delete [] s;
		return (nullptr);
	}
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
