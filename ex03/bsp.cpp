/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:14:31 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/02 19:48:40 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

typedef struct s_node
{
//	t_segment	*segments[3];
	struct s_node		*front;
	struct s_node		*back;
	bool		leaf;
	bool		solid;
} t_node;


/*
int	init_segment(t_segment & s, const Point & p1, const Point & p2, const Point convexTo);
Fixed	clasifyPoint(const Point & p, const t_segment & s);
t_node	*bspMakeTree(t_segment **s);

*/
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void) point;
	(void) a;
	(void) b;
	(void) c;

	Segment s[3] = {Segment(a,b,c), Segment(a,c,b), Segment(b,c,a)}; 

	s[0].print();
	s[1].print();
	s[2].print();

	for (int i = 0; i < 3; i++)
	{
		if (s[i].good() == 0)
		{
			s[i].print();
			std::cout << "Not a valid triangle" << std::endl;
			return (false);
		}
	}
	return (true);
}

/*
t_node	*bspMakeTree(t_segment **s)
{
	(void) s;
	t_node *tree = NULL;


	//TODO


	return (tree);
}
*/
