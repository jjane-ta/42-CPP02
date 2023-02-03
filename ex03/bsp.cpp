/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:14:31 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/03 20:23:38 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

//BspNode	*bspMakeTree(Segment **s);
Segment	**bsp_init_segments(Point const a, Point const b, Point const c);
Segment **bsp_clean_segments(Segment **s);


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void) point;
		
	BspNode	*bspTree;
	Segment **s = bsp_init_segments(a, b, c);
	if (!s)
	{
		std::cout << "Not a valid triangle" << std::endl;
		return (false);
	}
	//debug
	s[0]->print();
	s[1]->print();
	s[2]->print();

	bspTree = new BspNode(s);

	
	// Consulta el arbol con el punto

	bsp_clean_segments(s);
	delete bspTree;

	return (true);
}


Segment	**bsp_init_segments(Point const a, Point const b, Point const c)
{
	Segment **s = new (Segment(*[4]));
	
	s[0] = new Segment(a,b,c);
	s[1] = new Segment(a,c,b);
	s[2] = new Segment(b,c,a);
	s[3] = nullptr;
	if (!s[0]->good() || !s[1]->good() || !s[2]->good())
		return (bsp_clean_segments(s));
	return (s);
}

Segment **bsp_clean_segments(Segment **s)
{
	int i = 0;
	while (s && s[i])
		delete s[i++];
	delete s;
	return (nullptr);
}
