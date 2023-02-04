/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:12:59 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/02/04 20:16:18 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "BspNode.hpp"

static void	main_print_banner(std::string title);

int main( void )
{
	std::cout << std::endl;
	main_print_banner("Inside test");
	{
		if (bsp(Point(0,0), Point(0,3), Point(3,3), Point(0.01,1)))
			std::cout << "\nINSIDE" << std::endl;
		else
			std::cout << "\nOUTSIDE" << std::endl;
		std::cout << std::endl; 
	}
	main_print_banner("\nOutside test");
	{
		std::cout << "Point back AB";
		if (bsp(Point(0,0), Point(3,3), Point(0,3), Point(-1,2)))
			std::cout << "\nINSIDE" << std::endl;
		else
			std::cout << "\nOUTSIDE" << std::endl;
		std::cout << std::endl; 
		std::cout << "Point back AC";
		if (bsp(Point(0,0), Point(3,3), Point(0,3), Point(2,1)))
			std::cout << "\nINSIDE" << std::endl;
		else
			std::cout << "\nOUTSIDE" << std::endl;
		std::cout << std::endl; 
		std::cout << "Point back BC";
		if (bsp(Point(0,0), Point(3,3), Point(0,3), Point(2,5)))
			std::cout << "\nINSIDE" << std::endl;
		else
			std::cout << "\nOUTSIDE" << std::endl;
		std::cout << std::endl; 
	}
	main_print_banner("On edge test");
	{
		if (bsp(Point(0,0), Point(3,3), Point(0,3), Point(0,3)))
			std::cout << "\nINSIDE" << std::endl;
		else
			std::cout << "\nOUTSIDE" << std::endl;
		std::cout << std::endl; 
	}
	main_print_banner("BAD triangle test");
	{
		std::cout << "Vetices en la misma recta no forman un triangulo => ";
		bsp(Point(0,0), Point(3,3), Point(6,6), Point(0,3));
		std::cout << std::endl; 
		std::cout << "Vetices repetidos no forman un triangulo => ";
		bsp(Point(0,0), Point(3,3), Point(3,3), Point(0,3));
		std::cout << std::endl; 
		std::cout << "1 : Puntos con el flag de error activo no son validos => ";
		bsp(Point(0.0f/0.0f,0), Point(0,3), Point(0,3), Point(0,3));
		std::cout << std::endl;
		std::cout << "2 : Puntos con el flag de error activo no son validos => ";
		Fixed z = Fixed::max();
		z++;		
		bsp(Point(z,0), Point(0,3), Point(0,3), Point(0,3));
		std::cout << std::endl; 

	}

	main_print_banner("BAD point test");
	{
		std::cout << "Puntos con el flag de error activo no son validos => ";
		bsp(Point(0,0), Point(0,3), Point(3,3), Point(0,0.0f/0.0f));
		std::cout << std::endl;
	}









	return 0;
}

static void	main_print_banner(std::string title)
{	
	std::cout	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	title	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	std::endl;
}
