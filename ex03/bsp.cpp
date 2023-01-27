/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:14:31 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/27 20:21:01 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

typedef struct s_segment
{
	Point p[2];
	Point dir;
	Point norm;
} t_segment;



bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void) a;
	(void) b;
	(void) c;
	(void) point;

	Point s_ab[2] = {a, b};
	Point s_ac[2] = {a, c};
	Point s_bc[2] = {b, c};

	Point v_ab;
	Point v_ac;
	Point n_ab;
	Fixed value;

	v_ab = Point::v_director(a, b);
	n_ab = Point::v_normal(v_ab);

	v_ac = Point::v_director(a, c);
	value = Point::p_escalar(n_ab, v_ac);
	

	std::cout << "a = "; a.print();
	std::cout << " | b = "; b.print();
	std::cout <<" | direction vector = "; v_ab.print();
	std::cout <<" | normal vector = "; n_ab.print();
	std::cout << std::endl;

	std::cout << "a = "; a.print();
	std::cout << " | c = "; c.print();
	std::cout <<" | direction vector = "; v_ac.print();
	std::cout << std::endl;

	std::cout << "Value = " << value << std::endl;



	return (true);
}




