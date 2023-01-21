/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:12:59 by jjane-ta          #+#    #+#             */
/*   Updated: 2023/01/21 19:18:34 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

void	main_print_banner(std::string title);

int main( void )
{
	main_print_banner("TEST 1");
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
			
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	main_print_banner("END TEST 1");

	main_print_banner("TEST 2");
	{
		Fixed a;

		a.setRawBits(1);
		Fixed b( a );
		Fixed c;
	
		c = b;
		b.setRawBits(2);

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	main_print_banner("END TEST 2");
	
	return 0;
}

void	main_print_banner(std::string title)
{	
	std::cout	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	title	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	std::endl;

}
